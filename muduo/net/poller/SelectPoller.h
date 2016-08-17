// Copyright 2010, Shuo Chen.  All rights reserved.
// http://code.google.com/p/muduo/
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.

// Author: Shuo Chen (chenshuo at chenshuo dot com)
//
// This is an internal header file, you should not include this.

#ifndef MUDUO_NET_POLLER_SELECTPOLLER_H
#define MUDUO_NET_POLLER_SELECTPOLLER_H

#include <muduo/net/Poller.h>

#include <vector>

struct pollfd;

namespace muduo
{
	namespace net
	{

		///
		/// IO Multiplexing with select(2).
		///
		class SelectPoller : public Poller
		{
		public:

			SelectPoller(EventLoop* loop);
			virtual ~SelectPoller();

			virtual Timestamp poll(int timeoutMs, ChannelList* activeChannels);
			virtual void updateChannel(Channel* channel);
			virtual void removeChannel(Channel* channel);

		private:
			void fillActiveChannels(int numEvents,
				ChannelList* activeChannels) const;

			typedef std::vector<struct pollfd> PollFdList;
			PollFdList pollfds_;
			fd_set rfds_;
			fd_set wfds_;
			fd_set efds_;
		};

	}
}
#endif  // MUDUO_NET_POLLER_SELECTPOLLER_H
