require comitup.inc

# v1.42
SRCREV = "cb25cf96b428a4a6cf30602a56c7433ead990951"

SRC_URI += " \
            git://github.com/davesteele/comitup;protocol=https;branch=main;rev=${SRCREV} \
           "

