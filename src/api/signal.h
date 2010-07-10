/* gmmproc5
 *
 * Copyright (C) 2010 Krzesimir Nowak
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef PROC_API_SIGNAL_H
#define PROC_API_SIGNAL_H

// api
#include "function.h"

namespace Proc
{

namespace Api
{

enum RunFlags
{
  RUN_INVALID = 0,
  RUN_FIRST = 1 << 0,
  RUN_LAST = 1 << 1
};

inline RunFlags
operator& (RunFlags first, RunFlags second)
{
  return RunFlags (static_cast<int> (first) & static_cast<int> (second));
}

inline RunFlags
operator| (RunFlags first, RunFlags second)
{
  return RunFlags (static_cast<int> (first) | static_cast<int> (second));
}

inline RunFlags
operator^ (RunFlags first, RunFlags second)
{
  return RunFlags (static_cast<int> (first) ^ static_cast<int> (second));
}

inline RunFlags&
operator|= (RunFlags& first, RunFlags second)
{
  return first = first | second;
}

inline RunFlags&
operator&= (RunFlags& first, RunFlags second)
{
  return first = first & second;
}

inline RunFlags&
operator^= (RunFlags& first, RunFlags second)
{
  return first = first ^ second;
}

inline RunFlags
operator~ (RunFlags first)
{
  return RunFlags (~static_cast<int> (first));
}

class Signal : public Function
{
public:
                  Signal (const std::string& id = std::string ());

  virtual         ~Signal ();

  inline RunFlags get_run_flags () const;
  bool            set_run_flags (RunFlags when);
private:
  RunFlags        m_run_flags;
};

inline RunFlags Signal::get_run_flags () const
{
  return m_run_flags;
}

} // namespace Api

} // namespace Proc

#endif // PROC_API_SIGNAL_H
