All commands, alphabetic order; letter J
========================================

This page contains the description of [\\j \\J](#cmd-j),
[\\jmath](#cmd-jmath), [\\jobname](#cmd-jobname), [\\Join](#cmd-Join),
[\\jot](#cmd-jot).

------------------------------------------------------------------------

\\j, \\J (constant) {#cmd-j}
-------------------

The `\j` command should produce a j without dot. Currently it produces a
normal j. See the `` `\AA `` \<doc-a.html\#cmd-Caa\>[\_\_ command. The
]{.title-ref}[J]{.title-ref}[ command expands to
]{.title-ref}[J]{.title-ref}[, but is converted to
]{.title-ref}[j]{.title-ref}[ by
]{.title-ref}[MakeLowercase]{.title-ref}\`.

\\jmath (constant) {#cmd-jmath}
------------------

The `\jmath` command is valid only in math mode. It generates a
miscellaneous symbol. `<mo>&jmath;</mo>` (Unicode U+6A, j) See
description of the `` `\ldots `` \<doc-l.html\#cmd-ldots\>\`\_\_
command.

\\jobname {#cmd-jobname}
---------

The expansion of `\jobname` is the name of the file that *Tralics* is
assumed to convert (without extension). In some cases, no file is
needed, and `\jobname` expands to `texput`.

\\Join (constant) {#cmd-Join}
-----------------

The `\Join` command is valid only in math mode. It generates a relation
symbol: `<mo>&bowtie;</mo>` (Unicode U+22C8, ⋈). See description of the
`` `\le `` \<doc-l.html\#cmd-le\>\`\_\_ command.

\\jot (rigid length) {#cmd-jot}
--------------------

This is 3pt in LaTeX, a little bit over one millimeter
