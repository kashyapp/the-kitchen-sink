# ~/.bashrc: executed by bash(1) for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples

# If not running interactively, don't do anything
[ -z "$PS1" ] && return

# don't put duplicate lines in the history. See bash(1) for more options
# don't overwrite GNU Midnight Commander's setting of `ignorespace'.
HISTCONTROL=$HISTCONTROL${HISTCONTROL+,}ignoredups
# ... or force ignoredups and ignorespace
HISTCONTROL=ignoreboth

# append to the history file, don't overwrite it
shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
HISTSIZE=10000

# check the window size after each command and, if necessary,
# update the values of LINES and COLUMNS.
shopt -s checkwinsize

# make less more friendly for non-text input files, see lesspipe(1)
[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"

# set variable identifying the chroot you work in (used in the prompt below)
if [ -z "$debian_chroot" ] && [ -r /etc/debian_chroot ]; then
    debian_chroot=$(cat /etc/debian_chroot)
fi

# set a fancy prompt (non-color, unless we know we "want" color)
case "$TERM" in
    xterm-color) color_prompt=yes;;
esac

# uncomment for a colored prompt, if the terminal has the capability; turned
# off by default to not distract the user: the focus in a terminal window
# should be on the output of commands, not on the prompt
force_color_prompt=yes

if [ -n "$force_color_prompt" ]; then
    if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
	# We have color support; assume it's compliant with Ecma-48
	# (ISO/IEC-6429). (Lack of such support is extremely rare, and such
	# a case would tend to support setf rather than setaf.)
	color_prompt=yes
    else
	color_prompt=
    fi
fi

if [ "$color_prompt" = yes ]; then
    PS1='${debian_chroot:+($debian_chroot)}\[\e[01;32m\]\u@\h\[\e[00m\]:\[\e[01;34m\]\w\[\e[00m\]\$ '
else
    PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
fi
unset color_prompt force_color_prompt

# If this is an xterm set the title to user@host:dir
case "$TERM" in
xterm*|rxvt*)
    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
    ;;
*)
    ;;
esac


# enable color support of ls and also add handy aliases
if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    alias ls='ls --color=auto'
    #alias dir='dir --color=auto'
    #alias vdir='vdir --color=auto'

    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
fi

# some more ls aliases
#alias ll='ls -l'
#alias la='ls -A'
#alias l='ls -CF'

# Alias definitions.
# You may want to put all your additions into a separate file like
# ~/.bash_aliases, instead of adding them here directly.
# See /usr/share/doc/bash-doc/examples in the bash-doc package.

if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

# enable programmable completion features (you don't need to enable
# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
# sources /etc/bash.bashrc).
if [ -f /etc/bash_completion ] && ! shopt -oq posix; then
    . /etc/bash_completion
fi


function lookup {
    for i in `echo $PATH|sed 's/:/\n/g'`
    do
    ls $i|grep -i $1
    done
}
export PATH=$HOME/local/bin:$PATH
export SCREENRC=$HOME/.screenrc
# function cd {
#     if [ -n "$1" ];then
#         pushd "$@" 
#     else
#         pushd $HOME
#     fi
# }
alias ch="pushd $HOME"
alias cd=pushd
alias d='dirs -v'
alias +=pushd
alias _=popd
alias cx='chmod +x'
alias grp='grep --exclude-dir=.svn --exclude=tags'

function symlink-tree {
    mkdir -p $1 || return 1;
    find -name .svn -prune -o \( -type d -exec mkdir -p $1/{} \; -o -exec ln -nsf $PWD/{} $1/{} \; \)
}

function psg {
    if [ $# -gt 0 ]; then
        pgrep $1|xargs ps -fwww;
    else
        echo "argument missing" >&2
    fi
}

# we need this PROMPT_COMMAND for screen to do the dynamic titling
case "$TERM" in
xterm*|rxvt*)
    PROMPT_COMMAND='echo -ne "\033]0;${PWD/$HOME/~}\007"'
    ;;
screen*)
    PROMPT_COMMAND='echo -ne "\033k\033\0134\033k`basename ${PWD}`\033\0134"'
    ;;
*)
    ;;
esac
export FIGNORE=CVS:\~:.o:.svn

export ENVLOC=$HOME/.bashvars
function grabvars {
    vars="
        SSH_AGENT_PID
        SSH_AUTH_SOCK
        GNOME_KEYRING_SOCKET
        GNOME_KEYRING_PID
        SESSION_MANAGER
        XAUTHORITY
        DBUS_SESSION_BUS_ADDRESS
        DISPLAY
        ";

    for i in $vars;do
        echo "${i}=\"${!i}\"";
    done > $ENVLOC
}
alias fixvars="source $ENVLOC"
alias screen="grabvars;screen"

if [ $TERM = "screen" ];then
    fixvars
fi;
alias dessert=telnet 122.166.106.120
