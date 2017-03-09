## Description

Adjust keyrepeat and delay until repeat, **without** requiring a user logout or reboot.

Confirmed working on MacOS Sierra (10.12.3), but should also work on prior versions.

This utility achieves the same effect as the typically used commands

```
# these commands require a reboot / relog for the new settings to take effect.

# default value seems to be 2 (30ms ?), each tick = 15ms
defaults write NSGlobalDomain KeyRepeat -int 1

# default value seems to be 15 (225ms ?), each tick = 15ms
defaults write NSGlobalDomain InitialKeyRepeat -int 10

```

This utility uses the same units as the above commands do.

## Usage
```
    # set repeat rate to 15ms
    krp -r | --repeat-rate 1

    # set delay until repeat to 135ms
    krp -d | --delay-until-repeat 9
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
