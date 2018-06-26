#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;
string reponse;

int main(int argc,char ** argv)
{
  if (argc>1) {
    for (int i=1;i<argc;i++){
      cout << "argument detected : " << argv[i] << endl;
      if (string(argv[i])=="-u"){
        system("sudo apt-get -y update && sudo apt-get -y upgrade");
      }
      else if (string(argv[i])=="-p"){
        system("sudo apt-get purge -y wolfram-engine bluej greenfoot nodered nuscratch scratch sonic-pi libreoffice claws-mail claws-mail-i18n minecraft-pi python-pygame");
      }
      else if (string(argv[i])=="-a"){
        system("sudo apt-get autoclean && sudo apt-get -y autoremove");
      }
      else if (string(argv[i])=="-r"){
        system("sudo reboot");
      }
      else if (string(argv[i])=="-i"){
        system("sudo apt-get install -y nautilus");
      }
      else if (string(argv[i])=="-opencv"){
        system("sudo apt-get install -y build-essential cmake cmake-curses-gui pkg-config");
        system("sudo apt-get install -y libjpeg-dev libtiff-dev libjasper-dev libpng12-dev libavcodec-dev libavformat-dev libswscale-dev libeigen3-dev libxvidcore-dev libx264-dev libgtk2.0-dev"); 
        system("sudo apt-get install -y libv4l-dev v4l-utils");
        system("sudo modprobe bcm2835-v4l2");
        system("sudo apt-get install -y libatlas-base-dev gfortran");
	system("sudo apt-get install -y python2.7-dev python2-numpy python3-dev python3-numpy");
	system("cd /home/pi");
	system("wget https://github.com/opencv/opencv/archive/3.4.0.zip -O opencv.zip");
	system("wget https://github.com/opencv/opencv_contrib/archive/3.4.0.zip -O opencv_contrib.zip");
	system("unzip opencv.zip");
        system("unzip opencv_contrib.zip");
	system("mkdir /home/pi/opencv-3.4.0/build");
        system("cd /home/pi/opencv-3.4.0/build");
	system("sudo cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D BUILD_WITH_DEBUG_INFO=OFF -D BUILD_DOCS=OFF -D BUILD_EXAMPLES=OFF -D BUILD_TESTS=OFF -D BUILD_opencv_ts=OFF -D BUILD_PERF_TESTS=OFF -D INSTALL_C_EXAMPLES=ON -D INSTALL_PYTHON_EXAMPLES=ON -D OPENCV_EXTRA_MODULES_PATH=/home/pi/opencv_contrib-3.4.0/modules -D ENABLE_NEON=ON -D WITH_LIBV4L=ON ..");
        system("sudo make -j4");
        system("sudo make install");
        system("sudo ldconfig");
      }
      else if (string(argv[i])=="-rpi"){
        system("sudo rpi-update");
      }
      else if (string(argv[i])=="-all"){
        system("sudo apt-get install -y nautilus");
        system("sudo apt-get purge -y wolfram-engine bluej greenfoot nodered nuscratch scratch sonic-pi libreoffice claws-mail claws-mail-i18n minecraft-pi python-pygame");
        system("sudo apt-get autoclean && sudo apt-get autoremove -y");
        system("sudo apt-get update -y && sudo apt-get upgrade -y");
	cout << "Do you want to install opencv ? It might take a long time to install it.\nPlease answer with 'yes' or 'no'\n ";
	while(1) {
		cin >> reponse;
		if (reponse=="yes"){
			system("sudo apt-get install -y build-essential cmake cmake-curses-gui pkg-config");
		        system("sudo apt-get install -y libjpeg-dev libtiff-dev libjasper-dev libpng12-dev libavcodec-dev libavformat-dev libswscale-dev libeigen3-dev libxvidcore-dev libx264-dev libgtk2.0-dev"); 
		        system("sudo apt-get install -y libv4l-dev v4l-utils");
		        system("sudo modprobe bcm2835-v4l2");
		        system("sudo apt-get install -y libatlas-base-dev gfortran");
			system("sudo apt-get install -y python2.7-dev python2-numpy python3-dev python3-numpy");
			system("cd /home/pi");
			system("wget https://github.com/opencv/opencv/archive/3.4.0.zip -O opencv.zip");
			system("wget https://github.com/opencv/opencv_contrib/archive/3.4.0.zip -O opencv_contrib.zip");
			system("unzip opencv.zip");
		        system("unzip opencv_contrib.zip");
			system("sudo rm opencv.zip opencv_contrib.zip");
			system("wget https://bootstrap.pypa.io/get-pip.py");
			system("sudo python get-pip.py");
			system("sudo python3 get-pip.py");
			system("sudo pip install numpy");
			system("mkdir /home/pi/opencv-3.4.0/build");
		        system("cd /home/pi/opencv-3.4.0/build");
			system("sudo cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D BUILD_WITH_DEBUG_INFO=OFF -D BUILD_DOCS=OFF -D BUILD_EXAMPLES=OFF -D BUILD_TESTS=OFF -D BUILD_opencv_ts=OFF -D BUILD_PERF_TESTS=OFF -D INSTALL_C_EXAMPLES=ON -D INSTALL_PYTHON_EXAMPLES=ON -D OPENCV_EXTRA_MODULES_PATH=/home/pi/opencv_contrib-3.4.0/modules -D ENABLE_NEON=ON -D WITH_LIBV4L=ON ..");
		        system("sudo make -j4");
		        system("sudo make install");
		        system("sudo ldconfig");
			break;
		}
		else if (reponse=="no"){
			break;
		}
		else {
			cout << "Can't understand what you wrote, please try again with 'yes' or 'no'\n";
			continue;
		}
	}
        system("sudo reboot");
      }
      else if (string(argv[i])=="-h"){
        cout << "use :\n -u to update and upgrade\n -p to purge unnecessary package\n -a to autoclean and autoremove\n -r to reboot\n -i to install useful packages\n -opencv to install opencv\n -all to do everything\n";
      }
      else {
        cout << "You are not using a good parameter, run this with -h argument to get informations on all possibilities\n";
      }
    }
  }
  else {
     cout << "use -h argument to get tips on commands\n";
  }
  return 0;
}
