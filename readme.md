# QMK Fork

This is my fork of [qmk_firmware](https://github.com/qmk/qmk_firmware).

## Keyboards

Other keyboard configs are kept on other branches (in parentheses):

* kbdfans/niu_mini (niu_mini)
* **keebio/iris** (iris)
* pauperboards/brick (brick)
* planck (planck)

I'm using different branches to effectively pin the version of qmk each board
is built with.

## Iris

This is the branch for my **keebio/iris** configuration. The keymap is in the
`keyboards/keebio/iris/keymaps/davidpratt512` directory.

Make the firmware with

```sh
make keebio/iris/rev6:davidpratt512[:flash]
```
