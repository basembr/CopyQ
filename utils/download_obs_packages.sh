#!/bin/bash
# Download packages from openSUSE Build Service.
version=$1
rpm_version=$2
user=${3:-"lukho"}
project=${4:-"copyq"}

base_url="http://download.opensuse.org/repositories/home:/"
url=$base_url$user:/$project

xdeb="-1_amd64.deb"
xdeb_i386="-1_i386.deb"
xrpm=".x86_64.rpm"

pkg="${project}_${version}"
pkg_deb="amd64/${pkg}${xdeb}"
pkg_deb_i386="i386/${pkg}${xdeb_i386}"
pkg_rpm="x86_64/${project}-${version}-${rpm_version}${xrpm}"

failed=""

die () {
    echo "ERROR: $*"
    exit 1
}

fetch_package () {
    name=$1
    package_url=$2
    wget -c "$package_url" -O "$name" || failed="$failed\n$package_url"
}

if [ -z "$version" ]; then
    die "First argument must be version package version!"
fi

fetch_package "${pkg}_Fedora_25${xrpm}"           "$url/Fedora_25/${pkg_rpm}"
fetch_package "${pkg}_Fedora_26${xrpm}"           "$url/Fedora_26/${pkg_rpm}"
fetch_package "${pkg}_Fedora_27${xrpm}"           "$url/Fedora_27/${pkg_rpm}"
fetch_package "${pkg}_Debian_8.0${xdeb_i386}"     "$url/Debian_8.0/${pkg_deb_i386}"
fetch_package "${pkg}_Debian_8.0${xdeb}"          "$url/Debian_8.0/${pkg_deb}"
fetch_package "${pkg}_Debian_9.0${xdeb_i386}"     "$url/Debian_9.0/${pkg_deb_i386}"
fetch_package "${pkg}_Debian_9.0${xdeb}"          "$url/Debian_9.0/${pkg_deb}"

if [ -n "$failed" ]; then
    echo -e "Failed packages:$failed"
    exit 2
fi

