inherit setuptools3 systemd

SUMMARY = "Comitup"
DESCRIPTION = "Wifi booststrapping using wifi"

SECTION = "devel/scripts"
LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM = "file://COPYING;md5=b234ee4d69f5fce4486a80fdaf4a4263"

DEPENDS = "python3-pbr-native "
RDEPENDS_${PN} = "avahi-autoipd avahi-daemon coreutils dnsmasq iw iputils-arping \
                  networkmanager systemd wpa-supplicant-cli python3-core \
                  python3-pycrypto python3-dbus python3-flask python3-jinja2  \
                  python3-networkmanager python3-pygobject python3-pyinotify \
                  python3-pkg-resources python3-plistlib python3-cachetools \
                  python3-pycairo python3-multiprocessing"

SRC_URI = " \
           file://comitup.service \
           file://comitup-web.service \
           file://0001-dbus-fix.patch \
          "

PYTHON_SITEPACKAGES_DIR ?= "/usr/share/comitup"

FILES_${PN} += "/lib/ /sbin/"

SYSTEMD_SERVICE_${PN} = " comitup.service"

do_install_append(){
    install -d ${D}${systemd_unitdir}/system
    install -m 0644 ${WORKDIR}/comitup.service ${D}${systemd_unitdir}/system
    install -m 0644 ${WORKDIR}/comitup-web.service ${D}${systemd_unitdir}/system

    #Hack for different location of wpa_cli
    install -d ${D}${base_sbindir}
    cd ${D}${base_sbindir}
    ln -s ../usr/sbin/wpa_cli wpa_cli
}


S = "${WORKDIR}/git/"
