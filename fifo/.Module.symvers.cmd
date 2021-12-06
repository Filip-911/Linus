cmd_/home/filip/linus/fifo/Module.symvers := sed 's/ko$$/o/' /home/filip/linus/fifo/modules.order | scripts/mod/modpost -m -a   -o /home/filip/linus/fifo/Module.symvers -e -i Module.symvers   -T -
