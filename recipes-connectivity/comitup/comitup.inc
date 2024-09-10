inherit setuptools3 systemd

SUMMARY = "Comitup"
DESCRIPTION = "Wifi booststrapping using wifi"

SECTION = "devel/scripts"
LICENSE = "GPL-2.0-or-later"
LIC_FILES_CHKSUM = "file://COPYING;md5=b234ee4d69f5fce4486a80fdaf4a4263"

DEPENDS = "python3-pbr-native python3-pytest-runner-native"
RDEPENDS:${PN} = "avahi-autoipd avahi-daemon coreutils dnsmasq iw iputils-arping \
                  networkmanager systemd wpa-supplicant-cli python3-core \
                  python3-dbus python3-flask python3-jinja2  \
                  python3-networkmanager python3-pygobject python3-unixadmin \
                  python3-pkg-resources python3-plistlib python3-cachetools \
                  python3-pycairo python3-multiprocessing"

SRC_URI = " \
           file://comitup.service \
           file://comitup-web.service \
          "

PYTHON_SITEPACKAGES_DIR ?= "${datadir}/comitup"

FILES:${PN} += " \
                /lib/ \
                /sbin/ \
                ${datadir} \
                ${systemd_unitdir}/system \
                ${localstatedir}/lib/comitup \
                /data/var/lib/comitup \
               "

SYSTEMD_SERVICE:${PN} = " comitup.service"

do_install:append(){
    install -d ${D}${systemd_unitdir}/system
    install -m 0644 ${WORKDIR}/comitup.service ${D}${systemd_unitdir}/system
    install -m 0644 ${WORKDIR}/comitup-web.service ${D}${systemd_unitdir}/system

    install -d ${D}${localstatedir}/lib/
    install -d ${D}/data/var/lib/comitup
    ln -sf /data/var/lib/comitup ${D}${localstatedir}/lib/comitup

    install -d ${D}${datadir}/dbus-1/system.d
    install ${S}/conf/comitup-dbus.conf ${D}${datadir}/dbus-1/system.d/comitup-dbus.conf

    install -d ${D}${datadir}/comitup/dns
    install ${S}/conf/dns-hotspot.conf ${D}${datadir}/comitup/dns/dns-hotspot.conf
    install ${S}/conf/dns-connected.conf ${D}${datadir}/comitup/dns/dns-connected.conf

    install -d ${D}${datadir}/comitup/web
    cp -r ${S}/web/templates ${D}${datadir}/comitup/web
}

S = "${WORKDIR}/git"

