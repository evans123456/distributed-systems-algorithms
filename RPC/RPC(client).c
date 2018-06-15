// p15/36969/2015
// EVANS WAHOME GICHUKI


#include <stdio.h>
#include "RPCops.h"

int main(int argc, char *argv[]) {



	CLIENT *client;
	char ans;
	char *server_addr; //Strings referenced by pointers, not stored in character arrays
	int server_port;
	int num1, numA[2];
	char *str;
	int *i_result; //Returned values will be pointers
	char **s_result;



	if (argc != 2 ) {

		fprintf(stderr, "Usage: %s [server address] \n", argv[0]);
		return(1); //Invalid argument number
	}

	server_addr = argv[1];
	;

	if((client = clnt_create(server_addr, RPCPROGRAM, RPCPROGVERS, "udp")) == NULL) {


		clnt_pcreateerror(server_addr);

		fprintf(stderr, "\ndid not establish a connection \n");

		return(2); //Failed to establish a connection
	}

	printf("Select operation to perform: \n[A]ddition \n[B]string reversal \n[N]umber squaring \n: ");
	scanf("%s", &ans);

	switch(ans) 
	{
		case 'a'||'A':
			//Addition
			printf("\nInput the first number: ");
			scanf("%d", &numA[0]);

			printf("\nInput the second number: ");
			scanf("%d", &numA[1]);

			i_result = addnum_1(numA, client);

			if(i_result == NULL) { //Cast since is a pointer or (result1 == (int *)NULL)
				clnt_perror(client, server_addr);
				fprintf(stderr, "\nError occurred while calling the server \nExiting... \n");


				return(4); //Error occurred while calling the server
			}

			printf("\nResult: %d", *i_result);
			break;
		case 'B'||'b':
		
			//String reversal

			printf("\nInput the string to reverse: ");
			scanf("%s", str);

			s_result = strrev_1(&str, client);


			if(s_result == NULL) {
				clnt_perror(client, server_addr);
				fprintf(stderr, "\nError occurred while calling the server \nExiting... \n");

				return(3); //Error occurred while calling the server
			}

			printf("\nResult: %s", *s_result);
			break;
		case 'N'||'n'://in the case of finding the square
		
			
			printf("\nInput the number to square: ");


			scanf("%d", &num1);

			sqnum_1(&num1, client);//calculate the square
			if(i_result ==  NULL) {

				clnt_perror(client, server_addr);

				fprintf(stderr, "\nError occurred while calling the server \nExiting... \n");

				return(3); //Error occurred while calling the server
			}

			printf("\nResult: %d", num1);
			break;
		default:
		//if you choose the wrong choice
			printf("\nYOU HAVE ENTERED A WRONG CHOICE \n");
			return(3); //Nonexistent operation chosen
	}



	clnt_destroy(client);//CLOSE THE CONNECTION
	return 0; //Normal termination
}