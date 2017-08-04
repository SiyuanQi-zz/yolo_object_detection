# obj detection by using kinect2

catkin_ws_path="/home/siyuan/old_catkin_ws/"
coconame_path=$(find "$(cd $catkin_ws_path; pwd)" -name "coco.names")
sed -i "/names = data\/coco.names/c\names = $coconame_path" $(find "$(cd ..; pwd)" -name "coco.data")

roslaunch yolo_object_detection yolo.launch
