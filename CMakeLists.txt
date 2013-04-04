cmake_minimum_required(VERSION 2.8)
project(arpack)

enable_language(Fortran)

option(WITH_MPI "Enable parallel support" OFF)

function(prefixlist list_name prefix)
    set(${list_name}_TMP)
    foreach(l ${${list_name}})
      list(APPEND ${list_name}_TMP ${prefix}${l} )
    endforeach()
    set(${list_name} "${${list_name}_TMP}" PARENT_SCOPE)
endfunction(prefixlist)

if (WITH_MPI)
    include(FindMPI)
    find_package(MPI REQUIRED)
    include_directories(${MPI_Fortran_INCLUDE_PATH})
    set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} ${MPI_Fortran_COMPILE_FLAG}")
endif()

set(arpackblas_DIR ${arpack_SOURCE_DIR}/BLAS/)
set(arpacklapack_DIR ${arpack_SOURCE_DIR}/LAPACK/)
set(arpackutil_DIR ${arpack_SOURCE_DIR}/UTIL/)
set(arpacksrc_DIR ${arpack_SOURCE_DIR}/SRC/)

if (WITH_MPI)
    set(parpackutil_DIR ${arpack_SOURCE_DIR}/PARPACK/UTIL/MPI/)
    set(parpacksrc_DIR ${arpack_SOURCE_DIR}/PARPACK/SRC/MPI/)
endif()

set(arpackblas_STAT_SRCS
    caxpy.f
    ccopy.f
    cdotc.f
    cdotu.f
    cgbmv.f
    cgemm.f
    cgemv.f
    cgerc.f
    cgeru.f
    cscal.f
    csscal.f
    cswap.f
    ctbsv.f
    ctrmm.f
    ctrsm.f
    ctrsv.f
    dasum.f
    daxpy.f
    dcopy.f
    ddot.f
    dgbmv.f
    dgemm.f
    dgemv.f
    dger.f
    dnrm2.f
    drot.f
    drotg.f
    dscal.f
    dswap.f
    dsymv.f
    dsyr2.f
    dtbsv.f
    dtrmm.f
    dtrsm.f
    dzasum.f
    dznrm2.f
    icamax.f
    idamax.f
    isamax.f
    izamax.f
    sasum.f
    saxpy.f
    scasum.f
    scnrm2.f
    scopy.f
    sdot.f
    sgbmv.f
    sgemm.f
    sgemv.f
    sger.f
    snrm2.f
    srot.f
    srotg.f
    sscal.f
    sswap.f
    ssymv.f
    ssyr2.f
    stbsv.f
    strmm.f
    strsm.f
    zaxpy.f
    zcopy.f
    zdotc.f
    zdotu.f
    zdscal.f
    zgbmv.f
    zgemm.f
    zgemv.f
    zgerc.f
    zgeru.f
    zscal.f
    zswap.f
    ztbsv.f
    ztrmm.f
    ztrsm.f
    ztrsv.f)

prefixlist(arpackblas_STAT_SRCS "${arpackblas_DIR}")

set(arpacklapack_STAT_SRCS
    cgbtf2.f
    clanhs.f
    ctrevc.f
    dlacon.f
    dlanst.f
    dlaruv.f
    dtrevc.f
    sgbtf2.f
    slaexc.f
    slaran.f
    slassq.f
    xlaenv.f
    zlahqr.f
    zmach.f
    cgbtrf.f
    clarf.f
    ctrexc.f
    dlacpy.f
    dlanv2.f
    dlascl.f
    dtrexc.f
    sgbtrf.f
    slagtm.f
    slarf.f
    slaswp.f
    zlange.f
    zrot.f
    cgbtrs.f
    clarfg.f
    ctrsen.f
    dladiv.f
    dlaptm.f
    dlaset.f
    dtrsen.f
    sgbtrs.f
    slahqr.f
    slarfg.f
    slasy2.f
    zgbtf2.f
    zlanhs.f
    ztrevc.f
    cgeqr2.f
    clarnv.f
    ctrsyl.f
    dlae2.f
    dlapy2.f
    dlasr.f
    dtrsyl.f
    sgeqr2.f
    slaln2.f
    slarfx.f
    sorm2r.f
    zgbtrf.f
    zlarf.f
    ztrexc.f
    cgttrf.f
    clartg.f
    cunm2r.f
    dlaev2.f
    dlapy3.f
    dlasrt.f
    dzsum1.f
    sgttrf.f
    slamch.f
    slarnd.f
    spttrf.f
    zgbtrs.f
    zlarfg.f
    ztrsen.f
    cgttrs.f
    clascl.f
    dgbtf2.f
    dlaexc.f
    dlaran.f
    dlassq.f
    icmax1.f
    sgttrs.f
    slange.f
    slarnv.f
    spttrs.f
    zgeqr2.f
    zlarnv.f
    ztrsyl.f
    clacgv.f
    claset.f
    dgbtrf.f
    dlagtm.f
    dlarf.f
    dlaswp.f
    ilaenv.f
    slabad.f
    slanhs.f
    slartg.f
    ssteqr.f
    zgttrf.f
    zlartg.f
    zunm2r.f
    clacon.f
    classq.f
    dgbtrs.f
    dlahqr.f
    dlarfg.f
    dlasy2.f
    izmax1.f
    slacon.f
    slanst.f
    slaruv.f
    strevc.f
    zgttrs.f
    zlascl.f
    clacpy.f
    claswp.f
    dgeqr2.f
    dlaln2.f
    dlarfx.f
    dorm2r.f
    lsame.f
    slacpy.f
    slanv2.f
    slascl.f
    strexc.f
    zlacgv.f
    zlaset.f
    cladiv.f
    clatrs.f
    dgttrf.f
    dlamch.f
    dlarnd.f
    dpttrf.f
    lsamen.f
    sladiv.f
    slaptm.f
    slaset.f
    strsen.f
    zlacon.f
    zlassq.f
    clahqr.f
    cmach.f
    dgttrs.f
    dlange.f
    dlarnv.f
    dpttrs.f
    slae2.f
    slapy2.f
    slasr.f
    strsyl.f
    zlacpy.f
    zlaswp.f
    clange.f
    crot.f
    dlabad.f
    dlanhs.f
    dlartg.f
    dsteqr.f
    scsum1.f
    slaev2.f
    slapy3.f
    slasrt.f
    xerbla.f
    zladiv.f
    zlatrs.f)

prefixlist(arpacklapack_STAT_SRCS "${arpacklapack_DIR}")

set(arpackutil_STAT_SRCS
    icnteq.f
    icopy.f
    iset.f
    iswap.f
    ivout.f
    svout.f
    smout.f
    dvout.f
    dmout.f
    cvout.f
    cmout.f
    zvout.f
    zmout.f)

prefixlist(arpackutil_STAT_SRCS "${arpackutil_DIR}")

set(arpacksrc_STAT_SRCS
    sgetv0.f
    slaqrb.f
    sstqrb.f
    ssortc.f
    ssortr.f
    sstatn.f
    sstats.f
    snaitr.f
    snapps.f
    snaup2.f
    snaupd.f
    snconv.f
    sneigh.f
    sngets.f
    ssaitr.f
    ssapps.f
    ssaup2.f
    ssaupd.f
    ssconv.f
    sseigt.f
    ssgets.f
    sneupd.f
    sseupd.f
    ssesrt.f
    dgetv0.f
    dlaqrb.f
    dstqrb.f
    dsortc.f
    dsortr.f
    dstatn.f
    dstats.f
    dnaitr.f
    dnapps.f
    dnaup2.f
    dnaupd.f
    dnconv.f
    dneigh.f
    dngets.f
    dsaitr.f
    dsapps.f
    dsaup2.f
    dsaupd.f
    dsconv.f
    dseigt.f
    dsgets.f
    dneupd.f
    dseupd.f
    dsesrt.f
    cnaitr.f
    cnapps.f
    cnaup2.f
    cnaupd.f
    cneigh.f
    cneupd.f
    cngets.f
    cgetv0.f
    csortc.f
    cstatn.f
    znaitr.f
    znapps.f
    znaup2.f
    znaupd.f
    zneigh.f
    zneupd.f
    zngets.f
    zgetv0.f
    zsortc.f
    zstatn.f)

prefixlist(arpacksrc_STAT_SRCS "${arpacksrc_DIR}")

if (WITH_MPI)
    set(parpackutil_STAT_SRCS
        pcmout.f
	pcvout.f
	pdmout.f
	pdvout.f
	pivout.f
	psmout.f
	psvout.f
	pzmout.f
	pzvout.f)

    prefixlist(parpackutil_STAT_SRCS "${parpackutil_DIR}")

    set(parpacksrc_STAT_SRCS
        debug.h
	pcgetv0.f
	pclarnv.f
	pcnaitr.f
	pcnapps.f
	pcnaup2.f
	pcnaupd.f
	pcneigh.f
	pcneupd.f
	pcngets.f
	pdgetv0.f
	pdlamch.f
	pdlarnv.f
	pdnaitr.f
	pdnapps.f
	pdnaup2.f
	pdnaupd.f
	pdneigh.f
	pdneupd.f
	pdngets.f
	pdnorm2.f
	pdsaitr.f
	pdsapps.f
	pdsaup2.f
	pdsaupd.f
	pdseigt.f
	pdseupd.f
	pdsgets.f
	pdznorm2.f
	pscnorm2.f
	psgetv0.f
	pslamch.f
	pslarnv.f
	psnaitr.f
	psnapps.f
	psnaup2.f
	psnaupd.f
	psneigh.f
	psneupd.f
	psngets.f
	psnorm2.f
	pssaitr.f
	pssapps.f
	pssaup2.f
	pssaupd.f
	psseigt.f
	psseupd.f
	pssgets.f
	pzgetv0.f
	pzlarnv.f
	pznaitr.f
	pznapps.f
	pznaup2.f
	pznaupd.f
	pzneigh.f
	pzneupd.f
	pzngets.f
	stat.h)

    prefixlist(parpacksrc_STAT_SRCS "${parpacksrc_DIR}")

endif()

add_library(arpack SHARED
		   ${arpackblas_STAT_SRCS}
		   ${arpacklapack_STAT_SRCS}
		   ${arpackutil_STAT_SRCS}
		   ${arpacksrc_STAT_SRCS})

set_target_properties(arpack PROPERTIES OUTPUT_NAME arpack)

if (WITH_MPI)
    add_library(parpack SHARED
		   	${parpacksrc_STAT_SRCS}
		   	${parpackutil_STAT_SRCS})
    set_target_properties(parpack PROPERTIES OUTPUT_NAME parpack)
endif ()
