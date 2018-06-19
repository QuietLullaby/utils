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
        cout << "condition -u detected\n";
        system("sudo apt-get update && sudo apt-get upgrade");
      }
      else if (string(argv[i])=="-p"){
        cout << "condition -p detected\n";
        system("sudo apt-get purge wolfram-engine bluej greenfoot nodered nuscratch scratch sonic-pi libreoffice claws-mail claws-mail-i18n minecraft-pi python-pygame");
      }
      else if (string(argv[i])=="-a"){
        cout << "condition -a detected\n";
        system("sudo apt-get autoclean && sudo apt-get autoremove");
      }
      else if (string(argv[i])=="-h"){
        cout << "use :\n -u to update and upgrade\n -p to purge unnecessary package\n -a to autoclean and autoremove\n -all to do everything\n";
      }
      else if (string(argv[i])=="-all"){
        cout << "condition -all detected\n";
        system("sudo apt-get update && sudo apt-get upgrade");
        system("sudo apt-get purge wolfram-engine bluej greenfoot nodered nuscratch scratch sonic-pi libreoffice claws-mail claws-mail-i18n minecraft-pi python-pygame");
        system("sudo apt-get autoclean && sudo apt-get autoremove");
      }
    }
  }
  else {
     cout << "use -h argument to get tips on commands\n";
  }
  return 0;
}
