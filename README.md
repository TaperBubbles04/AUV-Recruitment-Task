# AUV Recruitment Task

---

## 🛠️ How to Run My Code

Since I am using Docker to run ROS 2, you need to be inside the workspace folder to build it. I only learned the brief basics of Docker to get this environment running.

### Build

```bash
cd /ros_workspace
colcon build
source install/setup.bash
```

### Run Each Task

| Task | Command(s) |
|------|-----------|
| Task 1 | `ros2 run auv_recruitment task1` |
| Task 2 | `ros2 run auv_recruitment task2_pub` and `ros2 run auv_recruitment task2_process` and `ros2 run auv_recruitment task2_out`|
| Task 3 | `ros2 run auv_recruitment task3_commander` and `ros2 run auv_recruitment task3_navigator` |
| Task 4 | `ros2 run auv_recruitment task4` |

## 🐞 Bugs & Problems I Faced

### Task-Specific Coding Errors

**"Package Not Found" error:**
In Task 3, I initially forgot to add my custom message package (`auv_interfaces`) to `package.xml` and `CMakeLists.txt` of my Python package. This caused the navigator node to crash because it couldn't find the message definition.

**Sourcing Issues:**
I spent a long time wondering why my new nodes weren't showing up in `ros2 run`. I realized I have to run the `source` command in every new terminal I open, or the system won't see it.

**State Machine Logic:**
In Task 3, I originally had the submarine moving the wrong way when facing South because I messed up the `if/else` logic for coordinate updates. I had to think it through properly and work it out so that it actually moves in the proper way.

**Python Executable Permissions:**
When I first created the Python files, they wouldn't run as nodes. I had to learn to use `chmod +x` to make the scripts executable and ensure they were correctly linked in `setup.py`.

### Docker & Environment Issues

**Camera not working:**
For Task 4, the container couldn't see my laptop's webcam. I had to learn how to "pass through" the camera device and use `xhost +local:root` so the OpenCV window could appear on my desktop.

**Container Issue:**
I was trying to figure out how to give webcam permissions and use opencv with my container. In that process I created an image from my previous container and created a new container with the webcam permissions and deleted the old one. However when I ran the new container the files were missing. It took me a while to figure out but it was because I set up a Volume Mount to link my physical `ros2_work` folder to the container, so my work is saved on my actual laptop drive. I didnt know this because I didnt fully learn docker i just learn the very minimal to run my container. However I was able to set up a volume mount again to the new container and work with my code again.

**Git Branch Confusion:**
My local Git was set to `master` but GitHub wanted `main`. I then added the readme file while creating the repo which again caused a conflict while trying to push so I had to pull from the repo to get the readme file locally and then again track the changes and commit and push the files.

---

## 👤 Submission Details

| **Submitted by** | Tharanesh Suresh Kannan |
| **Roll No** | CS25B1054 |
| **Year** | 1st Year B.Tech CSE |