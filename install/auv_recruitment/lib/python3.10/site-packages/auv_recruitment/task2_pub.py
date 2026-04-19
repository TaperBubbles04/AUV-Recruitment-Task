import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32

class PubNode(Node):
    def __init__(self):
        super().__init__('node1_pub')
        self.pub = self.create_publisher(Int32, '/raw_signal', 10)
        self.timer = self.create_timer(1.0, self.send_num)
        self.count = 2

    def send_num(self):
        msg = Int32()
        msg.data = self.count
        self.pub.publish(msg)
        self.count += 2

def main(args=None):
    rclpy.init(args=args)
    node = PubNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()