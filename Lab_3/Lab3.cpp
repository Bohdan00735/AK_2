#include <stdio.h>
#include <unistd.h>
#include <map>
#include <string>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[]){
    int rez=0;
	map <string, bool> used; //to check repeat

	int option_index = -1;
	const char* short_options = "h::lvf:o:c:V::?"; 
	
	const struct option long_options[] = {
        {"help",0,NULL,'h'},
        {"list",0,NULL,'l'},
        {"version",0,NULL,'v'},
		{"find",0,NULL,'f'},
		{"open",0,NULL,'o'},
		{"copy",0,NULL,'c'},
		{"value",2,NULL,'V'},
        {NULL,0,NULL,0},
    };


	while ((rez = getopt_long(argc,argv,short_options,long_options, &option_index)) != -1){

		switch (rez){

		case 'h': { 
			if (used["h"] == false) {
                if (optarg) {
					printf("Help for command: %s \n", optarg); 
				} else {
					printf("Created by Melniichuk Bohdan\n There is help info") ; 
				}
				
				used["h"] = true;
				break;
			} 
			break;
		}
		
		case 'l': {
			if (used["l"] == false) {
				printf("Arg: List\n"); 
				used["l"] = true;
				break;
			}
			break;
		}


        case 'v': {
			if (used["v"] == false) {
				printf("Arg: version\n"); 
				used["v"] = true;
				break;
			}
			break;
		}

		case 'f': {
			if (used["f"] == false) {
				printf("find file :%s\n", optarg); 
				used["f"] = true;
				break;
			}
			break;
		}

		case 'o': {
			if (used["o"] == false) {
				printf("open file : %s\n", optarg); 
				used["o"] = true;
				break;
			}
			break;
		}

		case 'c': {
			if (used["c"] == false) {
				printf("copy file : %s\n", optarg); 
				used["c"] = true;
				break;
			}
			break;
		}

		case 'V': {
			if (used["V"] == false) {
				if (optarg == NULL) {
					printf("value without arg\n"); 
					used["V"] = true;
				} else {
					printf("write value: %s\n", optarg); 
					used["V"] = true;
				}
				
				break;
			}
			break;
		}

        case '?':{
            printf("Key not found \n");
            break;
        }


		default: {
			printf("Syntax error\n");
			break;
			}
        };
        
		option_index = -1;
	};
};
