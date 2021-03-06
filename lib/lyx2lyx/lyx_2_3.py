# -*- coding: utf-8 -*-
# This file is part of lyx2lyx
# -*- coding: utf-8 -*-
# Copyright (C) 2016 The LyX team
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

""" Convert files to the file format generated by lyx 2.3"""

import re, string
import unicodedata
import sys, os

# Uncomment only what you need to import, please.

#from parser_tools import find_token, find_end_of, find_tokens, \
#  find_token_exact, find_end_of_inset, find_end_of_layout, \
#  find_token_backwards, is_in_inset, get_value, get_quoted_value, \
#  del_token, check_token, get_option_value

#from lyx2lyx_tools import add_to_preamble, put_cmd_in_ert, get_ert, lyx2latex, \
#  lyx2verbatim, length_in_bp, convert_info_insets
#  insert_to_preamble, latex_length, revert_flex_inset, \
#  revert_font_attrs, hex2ratio, str2bool

from parser_tools import find_token

####################################################################
# Private helper functions



###############################################################################
###
### Conversion and reversion routines
###
###############################################################################

def revert_microtype(document):
    " Remove microtype settings. "
    i = find_token(document.header, "\\use_microtype", 0)
    if i == -1:
        return
    del document.header[i]



##
# Conversion hub
#

supported_versions = ["2.3.0", "2.3"]
convert = [
           [509, []]
          ]

revert =  [
           [508, [revert_microtype]]
          ]


if __name__ == "__main__":
    pass
