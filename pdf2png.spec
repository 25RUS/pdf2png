Summary:	PDF to PNG converter
Name:		pdf2png	
Version:	0.3
Release:	1
License:	GPLv3
Group:		Office 
Url:		https://github.com/25RUS/pdf2png
Source0:	%{name}-%{version}.tar.gz
BuildRequires:  cmake
BuildRequires:  qt5-devel
BuildRequires:	pkgconfig(Qt5Core)
BuildRequires:	pkgconfig(Qt5DBus)
BuildRequires:	pkgconfig(Qt5Gui)
BuildRequires:	pkgconfig(Qt5Widgets)
Requires: pdf2svg
Requires: inkscape

%description
PDF to PNG converter

%files
%doc LICENSE README.md
%{_bindir}/%{name}
%{_datadir}/applications/%{name}.desktop
%{_datadir}/pixmaps/%{name}.png

#------------------------------------------------------------------

%prep
%setup -q

%build
%cmake_qt5
%make

%install
%makeinstall_std -C build

mkdir -p %{buildroot}%{_datadir}/applications
cat > %{buildroot}%{_datadir}/applications/%{name}.desktop << EOF
[Desktop Entry]
Type=Application
Name=pdf2png
Comment=PDF to PNG converter
Exec=%{name}
Icon=%{name}
StartupNotify=false
Terminal=false
Categories=Qt;KDE;Office;Viewer;
EOF

# icon file
mkdir -p %{buildroot}%{_datadir}/pixmaps
install -m644 %{name}.png %{buildroot}%{_datadir}/pixmaps/






