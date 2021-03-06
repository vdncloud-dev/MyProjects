// DemuxerBase.h

#ifndef _PPBOX_DEMUX_DEMUXER_BASE_H_
#define _PPBOX_DEMUX_DEMUXER_BASE_H_

#include "ppbox/demux/base/DemuxBase.h"

#include <framework/configure/Config.h>

namespace ppbox
{
    namespace demux
    {

        class DemuxerBase
        {
        public:
            DemuxerBase(
                boost::asio::io_service & io_svc)
                : io_svc_(io_svc)
            {
            };

            virtual ~DemuxerBase() {}

        public:
            virtual boost::system::error_code open(
                boost::system::error_code & ec) = 0;

            virtual void async_open(
                open_response_type const & resp) = 0;

            virtual bool is_open(
                boost::system::error_code & ec) = 0;

            virtual boost::system::error_code cancel(
                boost::system::error_code & ec) = 0;

            virtual boost::system::error_code close(
                boost::system::error_code & ec) = 0;

        public:
            virtual boost::system::error_code get_media_info(
                MediaInfo & info, 
                boost::system::error_code & ec) const = 0;

            virtual size_t get_stream_count(
                boost::system::error_code & ec) const = 0;

            virtual boost::system::error_code get_stream_info(
                size_t index, 
                StreamInfo & info, 
                boost::system::error_code & ec) const = 0;

        public:
            virtual boost::system::error_code reset(
                boost::system::error_code & ec) = 0;

            virtual boost::system::error_code seek(
                boost::uint64_t & time, 
                boost::system::error_code & ec) = 0;

            virtual boost::uint64_t check_seek(
                boost::system::error_code & ec) = 0;

            virtual boost::system::error_code pause(
                boost::system::error_code & ec) = 0;

            virtual boost::system::error_code resume(
                boost::system::error_code & ec) = 0;

        public:
            virtual bool fill_data(
                boost::system::error_code & ec) = 0;

            virtual boost::system::error_code get_sample(
                Sample & sample, 
                boost::system::error_code & ec) = 0;

            virtual bool get_stream_status(
                StreamStatus & info, 
                boost::system::error_code & ec) = 0;

            virtual bool get_data_stat(
                DataStatistic & stat, 
                boost::system::error_code & ec) const = 0;

        public:
            boost::asio::io_service & get_io_service() const
            {
                return io_svc_;
            };

            framework::configure::Config & get_config()
            {
                return config_;
            };

        protected:
            framework::configure::Config config_;

        private:
            boost::asio::io_service & io_svc_;
        };

    } // namespace demux
} // namespace ppbox

#endif // _PPBOX_DEMUX_DEMUXER_BASE_H_
