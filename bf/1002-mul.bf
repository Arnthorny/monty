,>,			#Get the two digit input and store them in cell #1 and cell #2

>++++++++		#Move to Cell #3 and set it to 8
[
	<------		#Subtract 6 from Cell #2
	<------		#Subtract 6 from Cell #1
	>>>>++++++	#Add 6 to Cell #5
	<<-		#Decrement Cell #3 by 1
]			#Loop till Cell #3 gets to 0; Number of iter is 8

The result of this is:
Cell no :   1   	 2   		3	4	5
Contents:   i/p sub 48   i/p sub 48  	0 	0	48
Pointer :   				^

<<			#Move to Cell #1

[
	>		#Go to Cell #2
	[
		>+	#Move data to Cell #3
		>+	#Move data to Cell #4
		<<-	#Decrement cell #2 and loop
	]
	>>		#Go to cell #4
	[
		<<+	#Move data to Cell #2
		>>-	#Decrement data in Cell #4 and loop
	]
	<<<- 		#Decrement data in Cell #1 and loop
]

>>>>			#Move to Cell #5
[
	<<+		Increment Value in Cell #3 by 1
	>>-		Decrement Cell #5 by 1	
]

#Pointer now at Cell #5; Value of Cell #1 is now (Cell #1 x Cell #2) add 48

<<.			#Move to Cell #1 and print result
