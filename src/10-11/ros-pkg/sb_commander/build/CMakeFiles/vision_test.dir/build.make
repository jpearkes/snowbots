# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nwadams/sb/10-11/ros-pkg/sb_commander

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nwadams/sb/10-11/ros-pkg/sb_commander/build

# Include any dependencies generated for this target.
include CMakeFiles/vision_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vision_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vision_test.dir/flags.make

CMakeFiles/vision_test.dir/src/testing.o: CMakeFiles/vision_test.dir/flags.make
CMakeFiles/vision_test.dir/src/testing.o: ../src/testing.cpp
CMakeFiles/vision_test.dir/src/testing.o: ../manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/ros/tools/rospack/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/ros/core/roslib/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/messages/std_msgs/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/messages/rosgraph_msgs/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/ros/core/rosbuild/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/ros/core/roslang/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/clients/rospy/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/utilities/cpp_common/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/clients/cpp/roscpp_traits/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/utilities/rostime/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/clients/cpp/roscpp_serialization/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/utilities/xmlrpcpp/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/tools/rosconsole/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/clients/cpp/roscpp/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/ros/tools/rosclean/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/tools/rosgraph/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/tools/rosmaster/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/tools/rosout/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/tools/roslaunch/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/ros/tools/rosunit/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/tools/rostest/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/tools/topic_tools/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/tools/rosbag/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/tools/rosbagmigration/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/common_msgs/geometry_msgs/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/common_msgs/sensor_msgs/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /home/nwadams/sb/10-11/ros-pkg/sb_msgs/manifest.xml
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/messages/std_msgs/msg_gen/generated
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/messages/rosgraph_msgs/msg_gen/generated
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/clients/cpp/roscpp/msg_gen/generated
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/clients/cpp/roscpp/srv_gen/generated
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/ros_comm/tools/topic_tools/srv_gen/generated
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/common_msgs/geometry_msgs/msg_gen/generated
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/common_msgs/sensor_msgs/msg_gen/generated
CMakeFiles/vision_test.dir/src/testing.o: /opt/ros/diamondback/stacks/common_msgs/sensor_msgs/srv_gen/generated
CMakeFiles/vision_test.dir/src/testing.o: /home/nwadams/sb/10-11/ros-pkg/sb_msgs/msg_gen/generated
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nwadams/sb/10-11/ros-pkg/sb_commander/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/vision_test.dir/src/testing.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -o CMakeFiles/vision_test.dir/src/testing.o -c /home/nwadams/sb/10-11/ros-pkg/sb_commander/src/testing.cpp

CMakeFiles/vision_test.dir/src/testing.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vision_test.dir/src/testing.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -E /home/nwadams/sb/10-11/ros-pkg/sb_commander/src/testing.cpp > CMakeFiles/vision_test.dir/src/testing.i

CMakeFiles/vision_test.dir/src/testing.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vision_test.dir/src/testing.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -W -Wall -Wno-unused-parameter -fno-strict-aliasing -pthread -S /home/nwadams/sb/10-11/ros-pkg/sb_commander/src/testing.cpp -o CMakeFiles/vision_test.dir/src/testing.s

CMakeFiles/vision_test.dir/src/testing.o.requires:
.PHONY : CMakeFiles/vision_test.dir/src/testing.o.requires

CMakeFiles/vision_test.dir/src/testing.o.provides: CMakeFiles/vision_test.dir/src/testing.o.requires
	$(MAKE) -f CMakeFiles/vision_test.dir/build.make CMakeFiles/vision_test.dir/src/testing.o.provides.build
.PHONY : CMakeFiles/vision_test.dir/src/testing.o.provides

CMakeFiles/vision_test.dir/src/testing.o.provides.build: CMakeFiles/vision_test.dir/src/testing.o
.PHONY : CMakeFiles/vision_test.dir/src/testing.o.provides.build

# Object files for target vision_test
vision_test_OBJECTS = \
"CMakeFiles/vision_test.dir/src/testing.o"

# External object files for target vision_test
vision_test_EXTERNAL_OBJECTS =

../bin/vision_test: CMakeFiles/vision_test.dir/src/testing.o
../bin/vision_test: ../lib/libsb_commander.so
../bin/vision_test: CMakeFiles/vision_test.dir/build.make
../bin/vision_test: CMakeFiles/vision_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/vision_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vision_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vision_test.dir/build: ../bin/vision_test
.PHONY : CMakeFiles/vision_test.dir/build

CMakeFiles/vision_test.dir/requires: CMakeFiles/vision_test.dir/src/testing.o.requires
.PHONY : CMakeFiles/vision_test.dir/requires

CMakeFiles/vision_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vision_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vision_test.dir/clean

CMakeFiles/vision_test.dir/depend:
	cd /home/nwadams/sb/10-11/ros-pkg/sb_commander/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nwadams/sb/10-11/ros-pkg/sb_commander /home/nwadams/sb/10-11/ros-pkg/sb_commander /home/nwadams/sb/10-11/ros-pkg/sb_commander/build /home/nwadams/sb/10-11/ros-pkg/sb_commander/build /home/nwadams/sb/10-11/ros-pkg/sb_commander/build/CMakeFiles/vision_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vision_test.dir/depend

