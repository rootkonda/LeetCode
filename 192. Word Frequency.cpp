Write a bash script to calculate the frequency of each word in a text file words.txt.

For simplicity sake, you may assume:

words.txt contains only lowercase characters and space ' ' characters.
Each word must consist of lowercase characters only.
Words are separated by one or more whitespace characters.


cat words.txt - Outputs the content of words.txt file.
tr -s ' ' '\n' - replaces whitespaces with newline characters.
sort - sorts the contents in ascending order.
uniq -c - Returns the unique lines with count of similar adjacent lines. This will be in the format "3 the"
sort -nr -k 1 - sort the output in descending order based on first field.
awk '{print $2,$1}' - prints the required output.


cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -nr -k 1 | awk '{print $2, $1}'
