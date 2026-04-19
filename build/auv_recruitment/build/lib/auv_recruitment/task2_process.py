import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32

class ProcessNode(Node):
    def __init__(self):
        super().__init__('node2_process')
        self.sub = self.create_subscription(Int32, '/raw_signal', self.process_num, 10)
        self.pub = self.create_publisher(Int32, '/processed_signal', 10)

    def process_num(self, msg):
        new_num = msg.data * 5
        new_msg = Int32()
        new_msg.data = new_num
        self.pub.publish(new_msg)

def main(args=None):
    rclpy.init(args=args)
    node = ProcessNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()