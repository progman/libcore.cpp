//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// signal name
const char *libcore::get_signal_name(const int sig)
{
	struct
	{
		int sig;
		const char *sig_name;
	}
	signal_list[] =
	{
#ifdef SIGHUP
		{ SIGHUP,    "SIGHUP"    },
#endif
#ifdef SIGINT
		{ SIGINT,    "SIGINT"    },
#endif
#ifdef SIGQUIT
		{ SIGQUIT,   "SIGQUIT"   },
#endif
#ifdef SIGILL
		{ SIGILL,    "SIGILL"    },
#endif
#ifdef SIGABRT
		{ SIGABRT,   "SIGABRT"   },
#endif
#ifdef SIGFPE
		{ SIGFPE,    "SIGFPE"    },
#endif
#ifdef SIGKILL
		{ SIGKILL,   "SIGKILL"   },
#endif
#ifdef SIGSEGV
		{ SIGSEGV,   "SIGSEGV"   },
#endif
#ifdef SIGPIPE
		{ SIGPIPE,   "SIGPIPE"   },
#endif
#ifdef SIGALRM
		{ SIGALRM,   "SIGALRM"   },
#endif
#ifdef SIGTERM
		{ SIGTERM,   "SIGTERM"   },
#endif
#ifdef SIGUSR1
		{ SIGUSR1,   "SIGUSR1"   },
#endif
#ifdef SIGUSR2
		{ SIGUSR2,   "SIGUSR2"   },
#endif
#ifdef SIGCHLD
		{ SIGCHLD,   "SIGCHLD"   },
#endif
#ifdef SIGCONT
		{ SIGCONT,   "SIGCONT"   },
#endif
#ifdef SIGSTOP
		{ SIGSTOP,   "SIGSTOP"   },
#endif
#ifdef SIGTSTP
		{ SIGTSTP,   "SIGTSTP"   },
#endif
#ifdef SIGTTIN
		{ SIGTTIN,   "SIGTTIN"   },
#endif
#ifdef SIGTTOU
		{ SIGTTOU,   "SIGTTOU"   },
#endif
#ifdef SIGBUS
		{ SIGBUS,    "SIGBUS"    },
#endif
#ifdef SIGPOLL
		{ SIGPOLL,   "SIGPOLL"   },
#endif
#ifdef SIGPROF
		{ SIGPROF,   "SIGPROF"   },
#endif
#ifdef SIGSYS
		{ SIGSYS,    "SIGSYS"    },
#endif
#ifdef SIGTRAP
		{ SIGTRAP,   "SIGTRAP"   },
#endif
#ifdef SIGURG
		{ SIGURG,    "SIGURG"    },
#endif
#ifdef SIGVTALRM
		{ SIGVTALRM, "SIGVTALRM" },
#endif
#ifdef SIGXCPU
		{ SIGXCPU,   "SIGXCPU"   },
#endif
#ifdef SIGXFSZ
		{ SIGXFSZ,   "SIGXFSZ"   },
#endif
#ifdef SIGIOT
		{ SIGIOT,    "SIGIOT"    },
#endif
#ifdef SIGSTKFLT
		{ SIGSTKFLT, "SIGSTKFLT" },
#endif
#ifdef SIGIO
		{ SIGIO,     "SIGIO"     },
#endif
#ifdef SIGCLD
		{ SIGCLD,    "SIGCLD"    },
#endif
#ifdef SIGPWR
		{ SIGPWR,    "SIGPWR"    },
#endif
#ifdef SIGWINCH
		{ SIGWINCH,  "SIGWINCH"  },
#endif
#ifdef SIGUNUSED
		{ SIGUNUSED, "SIGUNUSED" },
#endif
		{ 0,         NULL }
	};

	for (size_t i=0; i < sizeof(signal_list)/sizeof(signal_list[0]); i++)
	{
		if ((signal_list[i].sig == sig) && (signal_list[i].sig_name != NULL))
		{
			return signal_list[i].sig_name;
		}
	}

	return "unknown";
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
