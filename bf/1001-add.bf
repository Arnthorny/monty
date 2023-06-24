,>,			#Get the two digit input and store them in cell #1 and cell #2
[
	<+		#Add 1 to Cell #1
	>-		#Subtract 1 from Cell #2 until it becomes 0
]

Cell #1 contains result of the ASCII addition = x; Pointer at Cell #2

>++++++++		#Set Cell #3 to 8
[
	<++++++		#Add 6 to Cell #2
	>-		#Subtract 1 from Cell #3
]			#Loop till Cell #3 becomes 0

Cell #2 now contains 48; Pointer at Cell #3

<			#Move to Cell #2
[
	<-		#Subtract 1 to Cell #1
	>-		#Subtract 1 from Cell #2
]			#Loop till Cell #2 becomes 0

Pointer at Cell #2; Cell #2 is 0; Cell #1 is now x sub 48;

<.			#Move to Cell #1 and print result
