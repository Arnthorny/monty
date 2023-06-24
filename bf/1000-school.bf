[ This program prints "School" and a newline to the screen

  This loop is an "initial comment loop", a simple way of adding a comment
  to a BF program such that you don't have to worry about any command
  characters. Any ".", ",", "+", "-", "<" and ">" characters are simply
  ignored, the "[" and "]" characters just have to be balanced. This
  loop and the commands it contains are ignored because the current cell
  defaults to a value of 0; the 0 value causes this loop to be skipped.
]
>+++++++++		Set Cell #1 to 9
[
    <+++++++++          Add 9 to Cell #0
    >-			Move to Cell #1 and subtract 1
]                   	Loop until Cell #1 is zero; Number of iterations is 9; Cell #0 becomes 81
<++.			Move to Cell #0 and add 2; 83 ASCII equivalent is 'S'
>++++			Set Cell #1 to 4
[
	<++++		Add 4 to Cell #0
	>-		Move to Cell #1 and subtract 1
]			Loop until Cell #1 is zero; Number of iter is 1; Cell #0 becomes 99
<.			Move to Cell #0 and print; This prints char 'c'
+++++.			Add 5 to Cell #0 and print 'h'
+++++++..		Add 7 to Cell #0 and print 'o' twice
---.			Subtract 3 from Cell #0 and print 'l'
[-]			Loops until the current cell has a value of 0
>+++++			Add 5 to Cell #1 
[
	<++		Add 2 to Cell #0 
	>-		Move to Cell #1 and subtract 1
]<.			Loop until Cell #1 becomes 0; Move to Cell #0 and print 10 == '\n'
