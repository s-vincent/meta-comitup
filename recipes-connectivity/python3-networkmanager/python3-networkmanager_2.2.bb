inherit setuptools3

SUMMARY = "Python 3 dbus networkmanager wrapper"
SECTION = "devel/scripts"
LICENSE = "Zlib"
LIC_FILES_CHKSUM = "file://COPYING;md5=9f8a5b5844f027357ab19ef3e3c6a956"

RDEPENDS_${PN} = "networkmanager python3-dbus python3-six"

SRC_URI = " \
            git://github.com/seveas/python-networkmanager;branch=main;protocol=https \
            file://0001-dbus-fix.patch \
          "
SRCREV = "9acb5c9d90154a68ffadd144e9d72f1b56038649"


S = "${WORKDIR}/git/"
