import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import sys
import threading

class ChatNode(Node):
    def __init__(self, name):
        super().__init__(f'chat_{name.lower()}')
        self.name = name
        self.pub = self.create_publisher(String, '/chat', 10)
        self.sub = self.create_subscription(String, '/chat', self.receive_msg, 10)

    def receive_msg(self, msg):
        if not msg.data.startswith(f"[{self.name}]"):
            self.get_logger().info(msg.data)

    def get_input(self):
        while rclpy.ok():
            try:
                text = input()
                if text:
                    msg = String()
                    msg.data = f"[{self.name}]: {text}"
                    self.pub.publish(msg)
            except EOFError:
                break

def main(args=None):
    rclpy.init(args=args)
    
    if len(sys.argv) < 2:
        print("Error: Provide a name")
        return

    name = sys.argv[1]
    node = ChatNode(name)

    thread = threading.Thread(target=node.get_input, daemon=True)
    thread.start()

    rclpy.spin(node)
    
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()