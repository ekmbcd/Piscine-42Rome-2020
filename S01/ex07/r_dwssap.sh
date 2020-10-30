cat /etc/passwd | grep -e ":" | sed -n "n;p" | cut -f1 -d":" | rev | sort -r | sed -n "$FT_LINE1, $FT_LINE2 p" | tr '\n' , | sed 's/,/, /g' | sed 's/\(.*\), /\1./' | tr -d '\n'
