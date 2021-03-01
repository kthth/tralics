All commands, alphabetic order; letter Y
========================================

This page contains the description of [\\year](#cmd-year),
[\\yearcite](#cmd-yearcite), [\\yscale](#cmd-yscale),
[\\yscalex](#cmd-yscalex), [\\y\@tag, \\\@ytag](#cmd-ytag).

------------------------------------------------------------------------

\\year (internal integer) {#cmd-year}
-------------------------

The `\year` counter is initially set to the current year and can be
changed by saying `\year=906`. The built-in command `\today` produces a
string like `2008/10/29 18:28:46`, that corresponds to the start of the
compilation, while the LaTeX command uses current values of `\year`,
`\month` and `\day`. (See [scanint](doc-s.html#fct-scanint) for details
of argument scanning). (See `` `\time `` \<doc-t.html\#cmd-time\>\`\_\_
for an example.)

\\yearcite (Tralics command) {#cmd-yearcite}
----------------------------

This is an extension of the `\cite` command, explained in section [2.8
Bibliography](raweb.html#rabib) of the raweb. The commands
`\yearcite{foo}` and `\yearcite[bar]{foo}` are equivalent to
`\cite[year][]{foo}` and `\cite[year][bar]{foo}`. They are also
equivalent to `\cite[][]{foo}` and `\cite[][bar]{foo}`.

\\yscale {#cmd-yscale}
--------

The `\yscale` command is defined by the curves package. The value is
`1.0`. See `` `\arc `` \<doc-a.html\#cmd-arc\>\`\_\_.

\\yscalex {#cmd-yscalex}
---------

The `\yscalex` command is defined by the curves package. The value is
`0.0`. See `` `\arc `` \<doc-a.html\#cmd-arc\>\`\_\_.

\\<y@tag>, \\\@ytag (Tralics commands) {#cmd-ytag}
--------------------------------------

Internal commands used for equation numbering, see `` `\tag ``
\<doc-t.html\#cmd-tag\>\`\_\_.
