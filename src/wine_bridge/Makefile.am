if WINE_PLUGIN

nodist_pkgdata_DATA = linuxtrack-wine.exe

if DARWIN
  MYLDFLAGS = -Wl,-no_arch_warnings
  linuxtrack-wine.exe : ltr_wine.nsi tester/Tester.exe.so controller/Controller.exe.so \
             client/NPClient.dll.so ft_client/FreeTrackClient.dll.so ft_tester/ftc.exe.so \
             client/check_data.exe.so views/TrackIR.exe.so
	install_name_tool -change $(WINE_PREFIX)/lib/libwine.1.dylib libwine.1.dylib tester/Tester.exe.so
	install_name_tool -change $(WINE_PREFIX)/lib/libwine.1.dylib libwine.1.dylib controller/Controller.exe.so 
	install_name_tool -change $(WINE_PREFIX)/lib/libwine.1.dylib libwine.1.dylib client/NPClient.dll.so
	install_name_tool -change $(WINE_PREFIX)/lib/libwine.1.dylib libwine.1.dylib ft_client/FreeTrackClient.dll.so
	install_name_tool -change $(WINE_PREFIX)/lib/libwine.1.dylib libwine.1.dylib ft_tester/ftc.exe.so
	install_name_tool -change $(WINE_PREFIX)/lib/libwine.1.dylib libwine.1.dylib client/check_data.exe.so
	install_name_tool -change $(WINE_PREFIX)/lib/libwine.1.dylib libwine.1.dylib views/TrackIR.exe.so
	makensis $<


else
  MYLDFLAGS = -Wl,--no-warn-search-mismatch

if WINE64
  linuxtrack-wine.exe : ltr_wine64.nsi tester/Tester.exe.so tester/Tester64.exe.so \
                        controller/Controller.exe.so client/NPClient.dll.so client/NPClient64.dll.so \
                        ft_client/FreeTrackClient.dll.so ft_tester/ftc.exe.so client/check_data.exe.so \
			views/TrackIR.exe.so
	makensis $<
else
  linuxtrack-wine.exe : ltr_wine.nsi tester/Tester.exe.so controller/Controller.exe.so client/NPClient.dll.so \
                        ft_client/FreeTrackClient.dll.so ft_tester/ftc.exe.so client/check_data.exe.so \
			views/TrackIR.exe.so
	makensis $<
endif #WINE64

endif #DARWIN


clean-local: clean-local-check
.PHONY: clean-local-check
clean-local-check:
	rm -f *.exe

distclean-local: distclean-local-check
.PHONY: distclean-local-check
distclean-local-check:
	rm -f *.exe

endif

dist_pkgdata_DATA = README.wine
EXTRA_DIST = linuxtrack.ico linuxtrack1.ico

