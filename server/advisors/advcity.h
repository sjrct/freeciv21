/********************************************************************** 
 Freeciv - Copyright (C) 1996 - A Kjeldberg, L Gregersen, P Unold
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
***********************************************************************/
#ifndef FC__ADVCITY_H
#define FC__ADVCITY_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct city;
struct adv_data;

int adv_eval_calc_city(struct city *pcity, struct adv_data *adv);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* FC__ADVCITY_H */
