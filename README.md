## Description

Adjust keyrepeat and delay until repeat, **without** requiring a user logout or reboot.

Confirmed working on MacOS Sierra (10.12.3), but should also work on prior versions.

This utility achieves the same effect as the typically used commands

```
# these commands require a reboot / relog for the new settings to take effect.

defaults write NSGlobalDomain KeyRepeat -int 1

defaults write NSGlobalDomain InitialKeyRepeat -int 10

```

This utility uses the same units as the above commands do.

## Usage
```
    # print version
    krp -v | --version

    # set repeat rate to 135ms, fastest value in system pref = 15 (225ms)
    krp -r | --repeat-rate 9

    # set delay until repeat to 15ms, fastest value in system pref = 2 (30ms)
    krp -d | --delay-until-repeat 1

    # each tick corresponds to 15ms
    # 1 = 15ms, 2 = 30ms, 3 = 45ms, ..
```

## Install
```
    brew install koekeishiya/formulae/krp
```

## Development

Requires Xcode-8 command line tools.

```
    make            # debug build
    make install    # optimized build
```
