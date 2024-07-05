enum PT_INDEX {
	PI_OVERALL=0,
	PI_GENERAL,
	PI_PRIORITY,
	PI_FILE_TYPES,
	PI_RECURSE,
	PI_SAVE_LIST,
	PI_LOGGING,
	PI_LOGFILE,
	PI_HTTPD,PI_HTTPD_PORT,
	PI_CHECK_UPDATE,

	PI_UI,
	PI_SHOW_CONSOLE,PI_QUIET,PI_SHOWMSG,PI_STATS,PI_VIEW,PI_SHOW_SPLASH,PI_FACE_ALPHA,
	
	PI_BATCH,
	PI_DEST_DIR,PI_TEMP_DIR,PI_OVERWRITE,PI_KEEP_UNFINISH,PI_KEEP_TEMP,PI_DEL_ORIGINAL,PI_POWEROFF,PI_TIMEOUT,

	PI_TAGGING_NAMING,
	PI_TAG,PI_FORMATTED_NAME,PI_NAME_FORMAT,PI_KEEP_DIR,PI_CREATE_DIR,

	PI_DECODE,
	PI_STARTPOS,PI_ENDPOS,PI_SLANG,PI_ALANG,PI_AID,PI_VID,PI_CHANNEL,PI_AUDIO_FILE,PI_CACHE_SIZE,PI_FORCE_SRATE,PI_FORCE_IDX,PI_MEDIAINFO,

	PI_AUDIO_OPTS,
	PI_ADEC,PI_AENC,PI_FORCE_WAVEFILE,PI_D_IN_PLUGINS,PI_DSP_PLUGINS,PI_D_DSP_PLUGINS,PI_ALL_AUDIO,PI_START_AID,PI_AUDIO_DELAY,

	PI_VIDEO_OPTS,
	PI_VENC,PI_VCODEC,PI_VMODE,PI_VBITRATE,PI_VQUALITY,PI_FPS,PI_CONSTANT_FPS,PI_AUTO_FPS,PI_AUTO_GEOMETRY,PI_AUTO_BITRATE,

	PI_MENCODER,
	PI_ME_DLL,PI_ME_PATH,PI_ME_OPTS,

	PI_PAGE_ADEC,
	PI_MP,PI_MP_DLL,PI_MP_BYPASS,PI_MP_PATH,PI_MP_OPTS,
	PI_WA,
	PI_WA_PATH,
	PI_WAVE,
	PI_WAVE_SRC,

	PI_PAGE_AENC,
	PI_LAME,
	PI_LAME_BITRATE,PI_LAME_QUANT,PI_LAME_VBRMIN,PI_LAME_VBRMAX,PI_LAME_QUALITY,
	PI_LAME_RATE,PI_LAME_STEREO,PI_LAME_REPLAYGAIN,PI_LAME_KAF,PI_LAME_LOWPASS,PI_LAME_HIPASS,PI_LAME_COPYRIGHT,PI_LAME_NONORIGINAL,
	PI_LAME_PROTECT,PI_LAME_NORES,PI_LAME_ENFORCE,PI_LAME_PATH,

	PI_3GPP,
	PI_3GPP_BITRATE,PI_3GPP_PS,PI_3GPP_DIR,

	PI_AMR,
	PI_AMR_CODEC,PI_AMR_MODE,PI_AMR_DTX,PI_AMR_PATH,

	PI_OGG,
	PI_OGG_MODE,PI_OGG_QUALITY,PI_OGG_BITRATE,PI_OGG_MIN,PI_OGG_MAX,PI_OGG_RESAMPLE,
	PI_OGG_DOWNMIX,PI_OGG_PATH,

	PI_AACP,
	PI_AACP_BITRATE,PI_AACP_MODE,PI_AACP_TYPE,PI_AACP_VER,PI_AACP_USEV1,PI_AACP_WORKAROUND,PI_AACP_PATH,

	PI_NE,
	PI_NE_PROFILE,PI_NE_MODE,PI_NE_QUALITY,PI_NE_BITRATE,PI_NE_HQ,PI_NE_DOWNMIX,PI_NE_HINT,PI_NE_PNS,PI_NE_PATH,

	PI_HLX,
	PI_HLX_AUDIENCE,PI_HLX_CONTENT,PI_HLX_PATH,

	PI_HMP3,
	PI_HMP3_MODE,PI_HMP3_BITRATE,PI_HMP3_VBRSCALE,PI_HMP3_STEREO,PI_HMP3_SB,PI_HMP3_IF,PI_HMP3_HF,PI_HMP3_SSE,PI_HMP3_OPTS,PI_HMP3_PATH,

	PI_FAAC,
	PI_FAAC_MODE,PI_FAAC_QUALITY,PI_FAAC_BITRATE,PI_FAAC_OBJTYPE,PI_FAAC_MPEGVER,
	PI_FAAC_TNS,PI_FAAC_MIDSIDE,PI_FAAC_SHORTCTL,PI_FAAC_PATH,

	PI_ITUNES,
	PI_ITUNES_KEEP,PI_ITUNES_PATH,

	PI_WMA,
	PI_WMA_CODEC,PI_WMA_MODE,PI_WMA_QUALITY,PI_WMA_BITRATE,PI_WMA_PATH,

	PI_MPC,
	PI_MPC_PROFILE,PI_MPC_PATH,

	PI_WV,
	PI_WV_BEST,PI_WV_HYBRID,PI_WV_BITRATE,PI_WV_CCF,PI_WV_EXTRA,PI_WV_PATH,PI_WV_OPTS,

	PI_FLAC,
	PI_FLAC_LEVEL,PI_FLAC_EMS,PI_FLAC_LPC,PI_FLAC_VERIFY,PI_FLAC_PATH,PI_FLAC_OPTS,

	PI_APE,
	PI_APE_LEVEL,PI_APE_PATH,

	PI_OFR,
	PI_OFR_MODE,PI_OFR_PATH,

	PI_PCM,
	PI_PCM_FORMAT,

	PI_CLI,
	PI_CLI_STDIN,PI_CLI_RAWPCM,PI_CLI_EXT,PI_CLI_CMD,

	PI_FF_AUDIO,
	PI_FF_ACODEC,PI_FF_ABITRATE,PI_FF_SR,PI_FF_PATH,PI_FF_OPTS,

	PI_PAGE_VCODEC,
	PI_XVID,
	PI_XVID_PROFILE,
	PI_XVID_BFRAME,
	PI_XVID_MQ,
	PI_XVID_INTERLACE,
	PI_XVID_GREY,
	PI_XVID_QPEL,
	PI_XVID_GMC,
	PI_XVID_TRELLIS,
	PI_XVID_CARTOON,
	PI_XVID_QUANTTYPE,
	PI_XVID_CM,
	PI_XVID_CO,
	PI_XVID_HQAC,
	PI_XVID_VHQ,
	PI_XVID_PACK,
	PI_XVID_THREADS,
	PI_XVID_EXTRAOPTS,
	PI_264,
	PI_264_TURBO,PI_264_ME,PI_264_MERANGE,PI_264_SUBQ,PI_264_MAXBF,PI_264_QP,
	PI_264_KEYINT,PI_264_KEYINTMIN,PI_264_FRAMEREF,PI_264_QPMIN,PI_264_QPMAX,PI_264_QPSTEP,PI_264_QCOMP,PI_264_THREADS,
	PI_264_EXTRAOPTS,
	PI_FF_VIDEO,
	PI_FF_TARGET,PI_FF_MBD,PI_FF_V4MV,PI_FF_OBMC,PI_FF_QPEL,PI_FF_DIA,PI_FF_TRELL,PI_FF_NR,PI_FF_QNS,PI_FF_HQ,PI_FF_ASPECT,
	PI_FF_KEYINT,PI_FF_MINRATE,PI_FF_MAXRATE,
	PI_FF_PSP,PI_FF_EXTRAOPTS,

	PI_CONTAINER_OPTS,PI_CONTAINER,
	PI_MKV,PI_MKV_PATH,PI_MKV_OPTS,
	PI_MP4BOX,PI_MP4_PACKED,PI_MP4_SBR,PI_MP4_SBRX,PI_MP4_MPEG4,PI_MP4_KEEPSYS,PI_MP4_ISMA,PI_MP4_3GP,PI_MP4BOX_PATH,PI_MP4BOX_OPTS,
	PI_MPG,PI_MPG_FORMAT,
	PI_LAVF,PI_LAVF_FORMAT,
	PI_PMP,PI_PMP_PATH,

	PI_AF,
	PI_DOWNMIX,
	PI_SHIBATCH,PI_SB_2PASS,PI_SB_SAMPLE_RATE,PI_SB_BITS,PI_SB_NORMAL,PI_SB_DITHER,PI_SB_PATH,
	PI_MPAF,
	PI_RESAMPLE,PI_RESAMPLE_FREQ,PI_RESAMPLE_HI,PI_RESAMPLE_METHOD,
	PI_EQ,PI_EQ_B0,PI_EQ_B9=PI_EQ_B0+9,
	PI_CHANNELS,
	PI_CHANNELS_NUM,PI_CHANNELS_CH0,PI_CHANNELS_CH5=PI_CHANNELS_CH0+5,
	PI_VOL,PI_VOL_GAIN,PI_VOL_SOFTCLIP,
	PI_SURROUND,PI_SURROUND_DELAY,
	PI_DELAY,PI_DELAY_CH0,PI_DELAY_CH5=PI_DELAY_CH0+5,
	PI_XSTEREO,PI_XSTEREO_CO,
	PI_VOLNORM,
	PI_COMP,
	PI_LADSPA,PI_LADSPA_FILE,PI_LADSPA_LABEL,PI_LADSPA_CTRL,
	PI_AF_EXTRA,

	PI_VF,
	PI_PP,PI_PP_DB,PI_PP_DR,PI_PP_AL,PI_PP_LB,PI_PP_TN,
	PI_SCALE,PI_SCALE_PRESET,PI_SCALE_WIDTH,PI_SCALE_HEIGHT,PI_SCALE_IS,PI_SCALE_CHROMA,PI_SCALE_ALG,PI_SCALE_KEEP_ASPECT,
	PI_EXPAND,PI_EXPAND_W,PI_EXPAND_H,PI_EXPAND_X,PI_EXPAND_Y,PI_EXPAND_SUB,PI_EXPAND_ASPECT,
	PI_CROP,PI_CROP_LEFT,PI_CROP_TOP,PI_CROP_WIDTH,PI_CROP_HEIGHT,
	PI_CROPDETECT,PI_LIMIT,PI_ROUND,PI_ROTATE,
	PI_DEN,
	PI_DEN_LUMA,PI_DEN_CHROMA,PI_DEN_TEMPORAL,
	PI_DEINTERLACE,
	PI_SCREENSHOT,
	PI_VF_MISC,PI_VF_EXTRA,

};