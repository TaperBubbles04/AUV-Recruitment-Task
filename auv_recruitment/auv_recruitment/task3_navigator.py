import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from auv_interfaces.msg import BotPose

class NavigatorNode(Node):
    def __init__(self):
        super().__init__('node2_navigator')
        self.sub = self.create_subscription(String, '/cmd', self.process_command, 10)
        self.pub = self.create_publisher(BotPose, '/bot_pose', 10)
        self.x = 0.0
        self.y = 0.0
        self.directions = ["North", "East", "South", "West"]
        self.facing_index = 0

    def process_command(self, msg):
        cmd = msg.data
        if cmd == "turn right":
            self.facing_index = (self.facing_index + 1) % 4
        elif cmd == "turn left":
            self.facing_index = (self.facing_index - 1) % 4
        elif cmd == "forward":
            self.move_bot(1.0)
        elif cmd == "backward":
            self.move_bot(-1.0)
        
        self.publish_pose()

    def move_bot(self, step):
        current_facing = self.directions[self.facing_index]
        if current_facing == "North":
            self.y += step
        elif current_facing == "East":
            self.x += step
        elif current_facing == "South":
            self.y -= step
        elif current_facing == "West":
            self.x -= step

    def publish_pose(self):
        pose = BotPose()
        pose.x = float(self.x)
        pose.y = float(self.y)
        pose.facing_direction = self.directions[self.facing_index]
        self.pub.publish(pose)
        self.get_logger().info(f"Position: ({pose.x}, {pose.y}) | Facing: {pose.facing_direction}")

def main(args=None):
    rclpy.init(args=args)
    node = NavigatorNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()