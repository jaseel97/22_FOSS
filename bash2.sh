clear
echo "OS Details"
str=$(uname -a)
echo $str
#echo Kernel Release : $(uname -r)
echo
echo "Available Shells"
echo $(grep '^[^#]' /etc/shells)
echo
echo "Mouse Settings"
echo $(xset -q | grep "acceleration")
