FILESEXTRAPATHS:append := ":${THISDIR}/files"

SRC_URI = " \
            git://github.com/seveas/python-networkmanager;branch=main;protocol=https \
            file://0001-dbus-fix.patch \
            file://0004-Fix-missing-dns-crash.patch \
            file://0005-KeyError-on-missing-Loopback.patch \
          "
SRCREV = "9acb5c9d90154a68ffadd144e9d72f1b56038649"
