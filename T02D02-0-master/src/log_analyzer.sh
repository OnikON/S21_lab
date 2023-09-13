#!/bin/bash

echo "введите путь к файлу"

read way

wc -l < $way

# buf touch need for save some inf
touch buf_for_do_sort_1290.txt
#save some trash in buf
cut -f 1 -d ' ' $way > buf_for_do_sort_1290.txt

sort buf_for_do_sort_1290.txt | uniq -u | wc -l

sort buf_for_do_sort_1290.txt | uniq -d | wc -l
#bye bye my buf
rm buf_for_do_sort_1290