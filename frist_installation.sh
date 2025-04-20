clear

cat << "EOF"
  ______  _              _     _
 (____  \| |            | |   | |
  ____)  ) | _____  ____| |  _| | ____ ___  ____
 |  __  (| |(____ |/ ___) |_/ ) |/ ___) _ \|  _ \
 | |__)  ) |/ ___ ( (___|  _ (| | |  | |_| | | | |
 |______/ \_)_____|\____)_| \_)_|_|   \___/|_| |_|
EOF
echo "  This is an UNOFFCIAL tool made only for Nothing Phone (2)"
echo "  This is a help tool to let you install BlackIron Project."
echo "  If you don't have OTA zip look rom.json in repo."
echo "  Frist installation require data formating !!!"
echo "  Rename your OTA to "ota.zip"."
echo "  Press any key to start."
read -n 1 -s -r
clear

if [ ! -f "./ota.zip" ]; then
    echo "No OTA found."
    exit 1
fi

read -p "Do you really want to lock bootloader? (y/N): " input
locked=0
if [ "$input" == "y" ] || [ "$input" == "Y" ]; then
    locked=1
fi

if [ $locked -eq 1 ] && [ ! -f "./avb_pkmd.bin" ]; then
    echo "Installing bootloader keys."
    wget -q --show-progress --content-disposition -O "avb_pkmd.bin" "https://pixeldrain.com/u/j6VWtnWe"
fi

if [ $locked -eq 1 ]; then
    ./avbroot ota verify -i ota.zip
    if [ $? -ne 0 ]; then
        echo "OTA is not integrated, aborting."
        exit 1
    fi
fi

fastboot=./platform-tools/fastboot
adb=./platform-tools/adb

$fastboot devices
$fastboot -w
$fastboot wipe-super super_empty.img
if [ $locked -eq 1 ]; then
    $fastboot erase avb_custom_key
    $fastboot flash avb_custom_key avb_pkmd.bin
fi
$fastboot reboot recovery

echo "Press any key when you turn sideload mode on."
read -n 1 -s -r

$adb sideload ota.zip

if [ $locked -eq 1 ]; then
    echo "Reboot device into bootloader."
    echo "Make sure everything to this step was done without errors !!!"
    echo "Press any key to lock."
    read -n 1 -s -r
    $fastboot flashing lock_critical
    $fastboot flashing lock
fi

echo "Done."

