from robot_control_class import RobotControl
import time

class ReactiveNavigator:
    def __init__(self, speed=0.2, min_distance=0.8, max_turns=4):
        self.rc = RobotControl(robot_name="summit")
        self.speed = speed
        self.min_distance = min_distance
        self.max_turns = max_turns
        self.turn_duration = 1.0  # seconds (adjust as needed)
        self.turn_speed = 0.5     # angular speed in rad/s

    def move_until_obstacle(self):
        print("Starting reactive movement...")
        turns_done = 0

        while not self.rc.ctrl_c and turns_done < self.max_turns:
            laser_ranges = self.rc.get_laser_full_summit()

            if laser_ranges is None or len(laser_ranges) < 200:
                print("Laser data not ready.")
                time.sleep(0.1)
                continue

            # Divide the laser into regions
            left = laser_ranges[0:66]
            front = laser_ranges[67:133]
            right = laser_ranges[134:200]

            # Get minimum distance in the front area
            front_min = min(front)

            if front_min > self.min_distance:
                # Move forward
                self.rc.cmd.linear.x = self.speed
                self.rc.cmd.angular.z = 0.0
                self.rc.publish_once_in_cmd_vel()
            else:
                print(f"Obstacle ahead! Closest at {front_min:.2f}m. Turning...")
                self.rc.stop_robot()
                self.rc.turn(clockwise="clockwise", speed=self.turn_speed, time=self.turn_duration)
                turns_done += 1

            time.sleep(0.1)

        self.rc.stop_robot()
        print("Finished reactive behavior.")

# No rospy here, just run the behavior directly
nav = ReactiveNavigator()
nav.move_until_obstacle()
