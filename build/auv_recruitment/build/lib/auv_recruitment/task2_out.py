import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32

class OutputNode(Node):
    def __init__(self):
        super().__init__('node3_output')
        self.sub = self.create_subscription(Int32, '/processed_signal', self.print_result, 10)

    def print_result(self, msg):
        final_num = msg.data + 10
        self.get_logger().info(f"Final Answer: {final_num}")

def main(args=None):
    rclpy.init(args=args)
    node = OutputNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()