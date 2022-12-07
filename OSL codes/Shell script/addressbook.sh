#Creating File
printf "Enter File Name :- "
read File
touch $File

#Lines
line(){
 echo "======================================================="
}


Display(){
 

 echo "FileName = $File"
 echo "-----------------------------------------------------------------"
 printf "%-15s" "Name"
 printf "%-15s" "Phone"
 printf "%-15s" "Street"
 printf "%-15s\n" "City"
 echo "-----------------------------------------------------------------"
 cat $File
}

Insert(){

 # check if file is new


 #To Read sr.no, name, ph_no, street, city, State, Pincode
 line
 echo "Inside Insert function"
 line

 printf "Enter name :- "
 read name

 printf "Enter mobile number :- "
 read pn

 # Check if mobile number has 10 digits
 while :; do
  if [[ ! $pn == [0-6]* && ${#pn} == 10 && $pn =~ [0-9]+$ ]]
  then break
  else
   printf "Please enter a valid phone number as XXXXXXXXXX: "
   read pn
   fi
 done

 while :; do
  if ! grep -q $pn $File
  then break
  else
   printf "Please enter a valid phone number as XXXXXXXXXX: "
   read pn
   fi
 done

 printf "Enter Street :- "
 read Street

 printf "Enter City :- "
 read city
 
 printf "Enter pincode :- "
 read pin
 
 while :; do
  if [[ ! $pin == 0* && ${#pin} == 6 && $pin =~ [0-9]+$ ]]
  then break
  else
   printf "Please enter a valid pin code number as XXXXXX: "
   read pin
   fi
 done


 printf "%-15s" "$name" >> $File
 printf "%-15s" "$pn" >> $File
 printf "%-15s" "$Street" >> $File
 printf "%-15s" "$city" >> $File
 printf "%-15s\n" "$pin" >> $File
 
}

Modify(){
 line
     echo "Inside Modify function"
 line
 
 echo "Modify by: "
 echo "1) Phone no."
 echo "2) Name "
 printf "Enter choice: "
 read choice

 case $choice in
  1) printf "Enter phone no to update: "
     read pattern
     printf "Enter new phone no: "
     read newpattern
     if grep -q $pattern $File
     then
      printf "Record Found \n"
      sed -i "s/$pattern/$newpattern/g" $File
     else
      printf "Record not found \n"
     fi
     ;;
  2) printf "Enter name: "
     read pattern
     printf "Enter new name: "
     read newpattern
     if grep -q $pattern $File
     then
      printf "Record Found \n"
      sed -i "s/$pattern/$newpattern/g" $File
     else
      printf "Record not found \n"
     fi
     ;;
  *) printf "Invalid choice" ;;
 esac
 
}

Search(){
 line
 echo "Inside Search function"
 line

 echo "Search by: "
 echo "1) Phone no."
 echo "2) Name "
 echo "3) Pin code"
 printf "Enter choice: "
 read choice

 case $choice in
  1) printf "Enter phone no: "
     read pattern
     if grep -q $pattern $File
     then
      printf "Record found\n"
      line
      grep -h $pattern $File
     else
      printf "Record not found \n"
     fi
     ;;
  2) printf "Enter name: "
     read pattern
     if grep -q $pattern $File
     then
      printf "Record found\n"
      line
      grep -h $pattern $File
     else
      printf "Record not found \n"
     fi
     ;;
  3) printf "Enter pincode: "
     read pattern
     if grep -q $pattern $File
     then
      printf "Record found\n"
      line
      grep -h $pattern $File
     else
      printf "Record not found \n"
     fi
     ;;
  *) printf "Invalid choice" ;;
 esac
 
}

Sort(){
 line
 echo "Inside Sort function"
  line
 
  echo "Sort by: "
 echo "1) Phone no."
 echo "2) Name "
 echo "3) Pin code"
 printf "Enter choice: "
 read choice
 line
 case $choice in
  1) sort -k 2 $File
     ;;
  2) sort -k 1 $File
     ;;
  3) sort -k 5 $File
     ;;
  *) printf "Invalid choice" ;;
 esac
 
}

Delete(){
 line
 echo "Inside Delete function"
 line
 
 echo "Delete by: "
 echo "1) Phone no."
 echo "2) Name "
 printf "Enter choice: "
 read choice

 case $choice in
  1) printf "Enter phone no: "
     read pattern
     if grep -q $pattern $File
     then
      printf "Record Found \n"
      sed -i "/$pattern/d" $File
     else
      printf "Record not found \n"
     fi
     ;;
  2) printf "Enter name: "
     read pattern
     if grep -q $pattern $File
     then
      printf "Record Found \n"
      sed -i "/$pattern/d" $File
     else
      printf "Record not found \n"
     fi
     ;;
  *) printf "Invalid choice" ;;
 esac
 
}


# Main function
 
# Menu
while :; do

 line
 echo "Menu--- : "
 echo "1) To Display Record"
 echo "2) To Insert Record"
 echo "3) To Modify Record"
 echo "4) To Search Record"
 echo "5) To Sort Record"
 echo "6) To Delete Record"
 echo "7) To Exit"
 line

 read Choice
 case $Choice in
  1) Display ;;
  2) Insert ;;
  3) Modify ;;
  4) Search ;;
  5) Sort ;;
  6) Delete ;;
  7) exit ;;
  *) echo "Error : Enter Proper Choice" ;;
 esac
done