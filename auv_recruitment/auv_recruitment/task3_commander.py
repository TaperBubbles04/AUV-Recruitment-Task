import rclpy
from rclpy.node import Node
from std_msgs.msg import String

def main(args=None):
    rclpy.init(args=args)
    
    node = Node('node1_commander')
    pub = node.create_publisher(String, '/cmd', 10)

    node.get_logger().info("Commander Ready! Valid orders: forward, backward, turn left, turn right. Type 'quit' to exit.")

    while rclpy.ok():
        cmd = input("Awaiting Order > ").strip().lower()
        
        if cmd == 'quit':
            break
            
        if cmd in ['forward', 'backward', 'turn left', 'turn right']:
            msg = String()
            msg.data = cmd
            pub.publish(msg)
        else:
            print("Invalid command.")

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()