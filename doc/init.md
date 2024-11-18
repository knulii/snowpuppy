Sample init scripts and service configuration for snowpuppycoind
==========================================================

Sample scripts and configuration files for systemd, Upstart and OpenRC
can be found in the contrib/init folder.

    contrib/init/snowpuppycoind.service:    systemd service unit configuration
    contrib/init/snowpuppycoind.openrc:     OpenRC compatible SysV style init script
    contrib/init/snowpuppycoind.openrcconf: OpenRC conf.d file
    contrib/init/snowpuppycoind.conf:       Upstart service configuration file
    contrib/init/snowpuppycoind.init:       CentOS compatible SysV style init script

Service User
---------------------------------

All three Linux startup configurations assume the existence of a "snowpuppycoincore" user
and group.  They must be created before attempting to use these scripts.
The OS X configuration assumes snowpuppycoind will be set up for the current user.

Configuration
---------------------------------

At a bare minimum, snowpuppycoind requires that the rpcpassword setting be set
when running as a daemon.  If the configuration file does not exist or this
setting is not set, snowpuppycoind will shutdown promptly after startup.

This password does not have to be remembered or typed as it is mostly used
as a fixed token that snowpuppycoind and client programs read from the configuration
file, however it is recommended that a strong and secure password be used
as this password is security critical to securing the wallet should the
wallet be enabled.

If snowpuppycoind is run with the "-server" flag (set by default), and no rpcpassword is set,
it will use a special cookie file for authentication. The cookie is generated with random
content when the daemon starts, and deleted when it exits. Read access to this file
controls who can access it through RPC.

By default the cookie is stored in the data directory, but it's location can be overridden
with the option '-rpccookiefile'.

This allows for running snowpuppycoind without having to do any manual configuration.

`conf`, `pid`, and `wallet` accept relative paths which are interpreted as
relative to the data directory. `wallet` *only* supports relative paths.

For an example configuration file that describes the configuration settings,
see `contrib/debian/examples/snowpuppycoin.conf`.

Paths
---------------------------------

### Linux

All three configurations assume several paths that might need to be adjusted.

Binary:              `/usr/bin/snowpuppycoind`  
Configuration file:  `/etc/snowpuppycoincore/snowpuppycoin.conf`  
Data directory:      `/var/lib/snowpuppycoind`  
PID file:            `/var/run/snowpuppycoind/snowpuppycoind.pid` (OpenRC and Upstart) or `/var/lib/snowpuppycoind/snowpuppycoind.pid` (systemd)  
Lock file:           `/var/lock/subsys/snowpuppycoind` (CentOS)  

The configuration file, PID directory (if applicable) and data directory
should all be owned by the snowpuppycoincore user and group.  It is advised for security
reasons to make the configuration file and data directory only readable by the
snowpuppycoincore user and group.  Access to snowpuppycoin-cli and other snowpuppycoind rpc clients
can then be controlled by group membership.

### Mac OS X

Binary:              `/usr/local/bin/snowpuppycoind`  
Configuration file:  `~/Library/Application Support/SnowPuppyCoinCore/snowpuppycoin.conf`  
Data directory:      `~/Library/Application Support/SnowPuppyCoinCore`
Lock file:           `~/Library/Application Support/SnowPuppyCoinCore/.lock`

Installing Service Configuration
-----------------------------------

### systemd

Installing this .service file consists of just copying it to
/usr/lib/systemd/system directory, followed by the command
`systemctl daemon-reload` in order to update running systemd configuration.

To test, run `systemctl start snowpuppycoind` and to enable for system startup run
`systemctl enable snowpuppycoind`

### OpenRC

Rename snowpuppycoind.openrc to snowpuppycoind and drop it in /etc/init.d.  Double
check ownership and permissions and make it executable.  Test it with
`/etc/init.d/snowpuppycoind start` and configure it to run on startup with
`rc-update add snowpuppycoind`

### Upstart (for Debian/Ubuntu based distributions)

Drop snowpuppycoind.conf in /etc/init.  Test by running `service snowpuppycoind start`
it will automatically start on reboot.

NOTE: This script is incompatible with CentOS 5 and Amazon Linux 2014 as they
use old versions of Upstart and do not supply the start-stop-daemon utility.

### CentOS

Copy snowpuppycoind.init to /etc/init.d/snowpuppycoind. Test by running `service snowpuppycoind start`.

Using this script, you can adjust the path and flags to the snowpuppycoind program by
setting the SNOWPUPPYCOIND and FLAGS environment variables in the file
/etc/sysconfig/snowpuppycoind. You can also use the DAEMONOPTS environment variable here.

### Mac OS X

Copy org.snowpuppycoin.snowpuppycoind.plist into ~/Library/LaunchAgents. Load the launch agent by
running `launchctl load ~/Library/LaunchAgents/org.snowpuppycoin.snowpuppycoind.plist`.

This Launch Agent will cause snowpuppycoind to start whenever the user logs in.

NOTE: This approach is intended for those wanting to run snowpuppycoind as the current user.
You will need to modify org.snowpuppycoin.snowpuppycoind.plist if you intend to use it as a
Launch Daemon with a dedicated snowpuppycoincore user.

Auto-respawn
-----------------------------------

Auto respawning is currently only configured for Upstart and systemd.
Reasonable defaults have been chosen but YMMV.
