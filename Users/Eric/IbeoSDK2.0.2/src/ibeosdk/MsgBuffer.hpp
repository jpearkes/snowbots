//======================================================================
/*! \file MsgBuffer.hpp
 *
 * \copydoc Copyright
 * \author Jan Christian Dittmer (jcd)
 * \date Jun 28, 2012
 *///-------------------------------------------------------------------

#ifndef IBEOSDK_MSGBUFFER_HPP_SEEN
#define IBEOSDK_MSGBUFFER_HPP_SEEN

//======================================================================

#include <ibeosdk/misc/WinCompatibility.hpp>

#include <ibeosdk/IbeoDataHeader.hpp>

#include <boost/asio.hpp>

//======================================================================

namespace ibeo {

//======================================================================
/*!\brief
 * \author Jan Christian Dittmer (jcd)
 * \version 1.0
 * \date Jun 28, 2012
 *
 * Class to receive ibeo messages from an TCP/IP socket and prepare them
 * for decoding.
 *///-------------------------------------------------------------------
class MsgBuffer {
public:
	//========================================
	/*!\brief Constructor
	 *
	 * \param[in, out]  recvSocket  Socket from which messages data
	 *                              will be received.
	 * \param[in]       bufSize     Size of the buffer
	 *                              which will be allocated
	 *                              to hold the received
	 *                              message data. This size has to be
	 *                              significantly larger than the largest
	 *                              to be expected message.
	 *///-------------------------------------
	MsgBuffer(boost::asio::ip::tcp::socket* recvSocket, const int bufSize);

	//========================================
	/*!\brief Destructor.
	 *///-------------------------------------
	virtual ~MsgBuffer();

public:
	//========================================
	/*!\brief Receive Messages from the device.
	 *
	 * \param[out] dh              If a complete message is in the buffer,
	 *                             \a dh will point to the attribute #dh which
	 *                             will contain the valid header data.
	 *                             Otherwise \a dh will be \t NULL.
	 * \param[out] startOfMsgBody  If a complete message is in the buffer,
	 *                             \a startOfMsgBody will point to the start
	 *                             of the message body inside the objects buffer.
	 *                             Otherwise \a startOfMsgBody will be \t NULL.
	 * \return \t true if a complete message is in the buffer, ready to be processed.
	 *         The message is described by \a dh and \a startOfMsgBody.
	 *         \t false There is no complete message in the buffer yet. \a dh and
	 *         \a startOfMsgBody will be NULL.
	 *///-------------------------------------
	bool recvMsg(const IbeoDataHeader*& dh, const char*& startOfMsgBody);

protected:
	//========================================
	/*!\brief Receive buffer will be completely cleaned.
	 *///-------------------------------------
	void clearBufferCompletely();

	//========================================
	/*!\brief Receive buffer will be cleaned but up to 3 bytes will be preserved.
	 *
	 * That is the first 3 bytes might contain the first 3 bytes of the magic word.
	 *///-------------------------------------
	void clearBufferPreserve3Bytes();

	//========================================
	/*!\brief Remove those bytes from the buffer which are scheduled for deletion.
	 *///-------------------------------------
	void removeScheduledBytes();

protected:
	//========================================
	/*!\brief Reduce the position of the given counter \a pos by \a nbOfBytes.
	 *
	 * But \a lowerLimit is the minimal value for the new position of \a pos.
	 * \param[in,out] pos         On entry the current position of the counter.
	 *                            On exit the new by \a nbOfBytes reduced position,
	 *                            or \a lowerLimit if the now position would be less
	 *                            than \a lowerLimit.
	 * \param[in]     nbOfBytes   Number of bytes the counter has to be reduced by.
	 * \param[in]     lowerLimit  Minimal value the counter is allowed to have after
	 *                            the reduction.
	 *///-------------------------------------
	static void reducePos(int& pos, const int nbOfBytes, const int lowerLimit=-1);

protected:
	//========================================
	/*!\brief Pointer to socket from which messages data will be received.
	 *///-------------------------------------
	boost::asio::ip::tcp::socket* m_socket;

	//========================================
	/*!\brief Size of the objects buffer #m_ptr.
	 *///-------------------------------------
	const int m_size;

	//========================================
	/*!\brief Pointer to the objects buffer.
	 *///-------------------------------------
	char* const m_ptr;

	//========================================
	/*!\brief Position to insert new data.
	 *
	 * The buffer is filled up to position #m_insAt-1.
	 * #m_insAt is the first not used byte in the buffer.
	 * The value has to be between 0 and #m_size-1.
	 *///-------------------------------------
	int m_insAt;

	//========================================
	/*!\brief Position of the last processed byte in the buffer.
	 *
	 * -1 means that no byte has been processed yet.
	 *///-------------------------------------
	int m_processedTo;

	//========================================
	/*!\brief Position up to which the data can be deleted inside the buffer.
	 *
	 * -1 means that no byte is there to be deleted.
	 *///-------------------------------------
	int m_scheduledForDeletionTo;

	//========================================
	/*!\brief Latest header data read from the message buffer.
	 *///-------------------------------------
	IbeoDataHeader m_dh;

	//========================================
	/*!\brief position of the latest header found in the message buffer.
	 *///-------------------------------------
	int m_dhAt;

	//========================================
	/*!\brief position of the body
	 *
	 * Has to be between -1 and #m_size-1. A value
	 * of -1 means no body found in the current
	 * buffer.
	 *///-------------------------------------
	int m_bodyAt;

	//========================================
	/*!\brief Size of the (to be) received message body.
	 *
	 * Has to be >= 0. Set to -1 if no header has been
	 * read which contains the body size informations.
	 *///-------------------------------------
	int m_bodySize;

	//========================================
	/*!\brief Number of bytes that are missing to complete
	 *        the message body.
	 *
	 * Set to -1 if buffer is empty/has been cleared.
	 *///-------------------------------------
	int m_missingBytes;

	//========================================
	/*!\brief Set if there is no not yet processed/reported
	 *        complete message in the buffer
	 *///-------------------------------------
	bool m_needToRecvData;
}; // MsgBuffer

//======================================================================

} // namespace ibeo

//======================================================================

#endif // IBEOSDK_MSGBUFFER_HPP_SEEN

//======================================================================

