/*
p15/36969/2016
evans wahome gichuki
 */

program RPCPROGRAM {
	version RPCPROGVERS {
		int ADDNUM(int) = 1; /* Return type and input type definition, and procedure number(1) */
		string STRREV(string) = 2; /* Procedure number(2) */
		int SQNUM(int) = 3; /* Procedure number(3) */
	} =1; /*Version  of the RPC program */
} = 0x20000003; /* Program number {20000000 - 3FFFFFFF} defined by user */