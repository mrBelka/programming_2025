FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Install SSH, X11, and basic utilities
RUN apt-get update && apt-get install -y \
    openssh-server \
    xorg \
    x11-apps \
    xterm \
    xauth \
    firefox \
    gedit \
    gnome-terminal \
    net-tools \
    iputils-ping \
    && rm -rf /var/lib/apt/lists/*

# Install development tools for custom X11 clients
RUN apt-get update && apt-get install -y \
    gcc \
    make \
    libx11-dev \
    libxext-dev \
    && rm -rf /var/lib/apt/lists/*

# Configure SSH
RUN mkdir /var/run/sshd
RUN echo 'root:password' | chpasswd
RUN sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed -i 's/#X11UseLocalhost yes/X11UseLocalhost no/' /etc/ssh/sshd_config
RUN echo "X11Forwarding yes" >> /etc/ssh/sshd_config
RUN echo "X11DisplayOffset 10" >> /etc/ssh/sshd_config

# Create a user for X11 applications
RUN useradd -m -s /bin/bash xuser && \
    echo 'xuser:password' | chpasswd

EXPOSE 22

CMD ["/usr/sbin/sshd", "-D"]