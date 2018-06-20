#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

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
      else if (string(argv[i])=="-all"){
        system("sudo apt-get install -y nautilus");
        system("sudo apt-get purge -y wolfram-engine bluej greenfoot nodered nuscratch scratch sonic-pi libreoffice claws-mail claws-mail-i18n minecraft-pi python-pygame");
        system("sudo apt-get update -y && sudo apt-get upgrade -y");
        system("sudo apt-get autoclean && sudo apt-get autoremove -y");
        system("sudo reboot");
      }
      else if (string(argv[i])=="-h"){
        cout << "use :\n -u to update and upgrade\n -p to purge unnecessary package\n -a to autoclean and autoremove\n -r to reboot\n -all to do everything\n";
      }
      else {
        cout << "You are not using a good parameter, run this with -h argument to get informations on all possibilities\n";
    }
  }
  else {
     cout << "use -h argument to get tips on commands\n";
  }
  return 0;
}
