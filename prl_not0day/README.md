# prl_not0day

This proof-of-concept demonstrates a trivial *no-bug, by-design* virtual machine guest-to-host escape with full arbitrary code execution on the current version of Parallels Desktop for Mac 16.5.0, both Intel and M1 varieties. The attack doesn't strictly require user interaction, and enables persistence on the host OS automatically. Tested with Guest OS Ubuntu 20.04.2 LTS. 

### Description

On all Unix-based operating systems of which MacOS is an instance, a write access to the user's home folder is a "game over" from the attacker's perspective. Hypervisors based on MacOS have to factor in that design peculiarity in new and unprecedented ways. 

Parallels Desktop for Mac version 16.5.0, exposes the host user's home directory as a Parallels Shared Folder to the Guest OS by default, immediately following the installation of Parallels Tools, with full read/write privileges. Such access to the host user's home directory enables a malicious Guest OS user to drop an executable binary on the host, and register it for both code execution and persistence in a variety of ways. This particular PoC registers the arbitrary-code binary in .zprofile (MacOS switched from bash to zsh some time ago), that would be launched each time a Terminal app is opened on the host. Another attack scenario would be to drop an additional .plist in LaunchAgents, that would launch the malicious binary each time a user logs in. 

As of today, a hypervisor is commonly assumed to enforce at least some basic security boundary and privilege separation between a VM and the host OS. If a particular hypervisor product or deployment includes design points that break this assumption, a user must be explicitly warned at the moment of starting a VM, without the need to dig out for some special hidden options or documentation notices. 

More details in the [blog post](https://zerodayengineering.com/blog/dont-share-your-home.html).

PS. This is NOT my Pwn2Own exploit, in which I used a real 0day bug and is currently in disclosure.

### TODO

* Include a prebuilt payload binary for Intel Mac.

### Author

Alisa Esage 
Email: contact@zerodayengineering.com
Twitter: @alisaesage
Github: @badd1e