#!/system/bin/sh

export KERNEL_PRODUCT=common_kernel_5.4.86

/data/local/tmp/kflattest IFS_START || { exit 2; }

# Remove the recipes and interface funcstions module if present
RECIPE_COUNT=$(lsmod | tail -n +2 | awk '{print $1}' | grep ${KERNEL_PRODUCT}_recipes | wc -l)
IFUNCS_COUNT=$(lsmod | tail -n +2 | awk '{print $1}' | grep ${KERNEL_PRODUCT}_ifuncs | wc -l)
[ $RECIPE_COUNT -gt 0 ] && rmmod ${KERNEL_PRODUCT}_recipes
[ $IFUNCS_COUNT -gt 0 ] && rmmod ${KERNEL_PRODUCT}_ifuncs

# Load new recipes/interface functions modules
insmod /data/local/tmp/${KERNEL_PRODUCT}_recipes.ko || { exit 2; }
insmod /data/local/tmp/${KERNEL_PRODUCT}_ifuncs.ko || { exit 2; }

echo "Running interface functions in the process $$"
/data/local/tmp/kflattest SET_FILTERPID "$$" || { exit 2; }

# Run interface functions
source /data/local/tmp/flat_triggers.sh

/data/local/tmp/kflattest IFS_STOP || { exit 2; }
