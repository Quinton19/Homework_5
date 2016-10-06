all: main
rebuild: clean main

main: robot_part.o controller.o view.o head.o arm.o locomotor.o torso.o battery.o main.o
	g++ robot_part.o controller.o view.o head.o arm.o locomotor.o torso.o battery.o

main.o: main.cpp controller.h
	g++ -c main.cpp
view.o: View.cpp Robot_Part.h View.h std_lib_facilities.h
	g++ -c View.cpp
controller.o: Controller.cpp Controller.h Head.h Locomotor.h Torso.h Battery.h Arm.h View.h std_lib_facilities.h
	g++ -c Controller.cpp
robot_part.o: Robot_Part.cpp Robot_Part.h 
	g++ -c Robot_Part.cpp
head.o: Head.cpp Head.h Robot_Part.h std_lib_facilities.h
	g++ -c Head.cpp
arm.o: Arm.cpp Arm.h Robot_Part.h std_lib_facilities.h
	g++ -c Arm.cpp
locomotor.o: Locomotor.cpp Locomotor.h Robot_Part.h std_lib_facilities.h
	g++ -c Locomotor.cpp
torso.o: Torso.cpp Torso.h Robot_Part.h std_lib_facilities.h
	g++ -c Torso.cpp
battery.o: Battery.cpp Battery.h Robot_Part.h std_lib_facilities.h
	g++ -c Battery.cpp


clean:
	rm -f *.o a.out a.exe