#!/usr/bin/env bash


cat <<- EOF
(the -n option suppresses automatic printing of lines)

There are three commands here: 1!G, h and $p. 1!G has an address, 1 (first line), but the ! means that the command will be executed everywhere but on the first line. $p on the other hand will only be executed on the last line. So what happens is this:

first line is read and inserted automatically into the pattern space
on the first line, first command is not executed; h copies the first line into the hold space.
now the second line replaces whatever was in the pattern space
on the second line, first we execute G, appending the contents of the hold buffer to the pattern buffer, separating it by a newline. The pattern space now contains the second line, a newline, and the first line.
Then, h command inserts the concatenated contents of the pattern buffer into the hold space, which now holds the reversed lines two and one.
We proceed to line number three -- go to the point (3) above.
Finally, after the last line has been read and the hold space (containing all the previous lines in a reverse order) have been appended to the pattern space, pattern space is printed with p. As you have guessed, the above does exactly what the tac command does -- prints the file in reverse.


EOF


echo "sample is: printf \"1\n2\n3\n\" | sed -n '1!G;h;\$p'"
echo "result is:"
printf "1\n2\n3\n" | sed -n '1!G;h;$p'