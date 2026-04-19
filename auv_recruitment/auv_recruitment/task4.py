import rclpy
from rclpy.node import Node
import cv2
import numpy as np

class VisualLockNode(Node):
    def __init__(self):
        super().__init__('node4_visual_lock')
        self.cap = cv2.VideoCapture(0)
        
        if not self.cap.isOpened():
            self.get_logger().error("FATAL: Cannot open webcam. Check your USB passthrough!")
            
        self.timer = self.create_timer(0.05, self.process_frame)
        self.current_state = "STARTING"

    def process_frame(self):
        ret, frame = self.cap.read()
        if not ret:
            return

        frame = cv2.flip(frame, 1)
        height, width, _ = frame.shape
        
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        
        lower_blue = np.array([100, 150, 0])
        upper_blue = np.array([140, 255, 255])
        mask = cv2.inRange(hsv, lower_blue, upper_blue)

        contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        obj_x = -1
        
        if contours:
            largest_contour = max(contours, key=cv2.contourArea)
            if cv2.contourArea(largest_contour) > 500:
                M = cv2.moments(largest_contour)
                if M["m00"] > 0:
                    obj_x = int(M["m10"] / M["m00"])
                    obj_y = int(M["m01"] / M["m00"])
                    cv2.circle(frame, (obj_x, obj_y), 10, (0, 255, 0), -1)

        output_frame = frame.copy()
        new_state = ""

        if obj_x == -1:
            new_state = "STATE 4: LOST - SEARCHING"
            output_frame = cv2.bitwise_not(frame)
        elif obj_x < width // 3:
            new_state = "STATE 1: ALIGNING LEFT"
            gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
            output_frame = cv2.cvtColor(gray, cv2.COLOR_GRAY2BGR)
        elif obj_x > (width // 3) * 2:
            new_state = "STATE 3: ALIGNING RIGHT"
            edges = cv2.Canny(frame, 100, 200)
            output_frame = cv2.cvtColor(edges, cv2.COLOR_GRAY2BGR)
        else:
            new_state = "STATE 2: LOCKED ON"
            output_frame = frame

        if new_state != self.current_state:
            self.get_logger().info(f"Transitioned to: {new_state}")
            self.current_state = new_state

        cv2.imshow("Operation Visual Lock", output_frame)
        cv2.waitKey(1)

def main(args=None):
    rclpy.init(args=args)
    node = VisualLockNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.cap.release()
        cv2.destroyAllWindows()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()