cmd_/home/filip/linus/fifo/modules.order := {   echo /home/filip/linus/fifo/fifo.ko; :; } | awk '!x[$$0]++' - > /home/filip/linus/fifo/modules.order
